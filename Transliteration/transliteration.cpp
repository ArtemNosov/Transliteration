#include "transliteration.h"
#include "ui_transliteration.h"

transliteration::transliteration(QWidget *parent) :
  QWidget(parent),
  ui_(new Ui::Transliteration){
  ui_->setupUi(this);
  this->setFixedSize(this->size());
  ui_->secondTextEdit->setReadOnly(true);
  ui_->bufferButton->setEnabled(false);
  //
  connect(ui_->translateButton, SIGNAL(clicked()), this, SLOT(TranslateButtonProcessing()));
  connect(ui_->bufferButton, SIGNAL(clicked()), this, SLOT(BufferButtonProcessing()));
}

void transliteration::TranslateButtonProcessing(){
  bool isFound = false;
  // Если выбран поиск по словарю, то открываем файл и ищем в нем наше слово.
  if (ui_->checkBox->isChecked()){
    QFile dictionary("dictionary.txt");
    dictionary.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream writeStream(&dictionary);
    writeStream.setCodec("UTF-8");
    writeStream.readLine();
    while (!writeStream.atEnd()) {
      // Берем из файла русский и латинский вариант и сравниваем со словом из первого "окна".
      QString rus = writeStream.readLine();
      QString eng = writeStream.readLine();
      if (ui_->rusButton->isChecked() && (ui_->firstTextEdit->toPlainText() == rus)){
        ui_->secondTextEdit->setText(eng);
        ui_->bufferButton->setEnabled(true);
        ui_->warningLabel->setText("");
        isFound = true;
      } else if (ui_->firstTextEdit->toPlainText() == eng){
        ui_->secondTextEdit->setText(rus);
        ui_->bufferButton->setEnabled(true);
        ui_->warningLabel->setText("");
        isFound = true;
      }
    }
    dictionary.close();
  }
  // Если поика по словарю не было или там ничего не было найдено,
  // то выполняем обычный перепод выбранным спообом.
  if (!isFound){
    QString resultText;
    QMap<QString, QString> map;
    // В зависимости от режима перевода, берем нужную нам "мапу".
    if (ui_->rusButton->isChecked()){
      map =  transliterationMethods_.GetRusMap(ui_->comboBox->currentIndex());
    } else {
      map =  transliterationMethods_.GetEngMap(ui_->comboBox->currentIndex());
    }
    // Сам перевод текста, с учетом букв, состоящих из нескольких символов.
    bool isCorrect = true;
    int index = 1;
    for (int i = 0; i < ui_->firstTextEdit->toPlainText().size(); i += index){
      if (map[ui_->firstTextEdit->toPlainText().mid(i, 4)] != ""){
        resultText += map[ui_->firstTextEdit->toPlainText().mid(i, 4)];
        index = 4;
      } else if (map[ui_->firstTextEdit->toPlainText().mid(i, 3)] != ""){
        resultText += map[ui_->firstTextEdit->toPlainText().mid(i, 3)];
        index = 3;
      } else if (map[ui_->firstTextEdit->toPlainText().mid(i, 2)] != ""){
        resultText += map[ui_->firstTextEdit->toPlainText().mid(i, 2)];
        index = 2;
      } else if (map[ui_->firstTextEdit->toPlainText().mid(i, 1)] != ""){
        resultText += map[ui_->firstTextEdit->toPlainText().mid(i, 1)];
        index = 1;
      } else{
        isCorrect = false;
      }
    }
    // Если слово удалось перевести, то выводим его, иначе выводим ошибку.
    if (isCorrect){
      ui_->secondTextEdit->setText(resultText);
      ui_->bufferButton->setEnabled(true);
      ui_->warningLabel->setText("");
    } else{
      ui_->bufferButton->setEnabled(false);
      ui_->warningLabel->setText("Провертье введенные данные!");
      ui_->secondTextEdit->clear();
    }
  }
}

void transliteration::BufferButtonProcessing(){
  // Сохраняем результат в буфер.
  QApplication::clipboard()->setText(ui_->secondTextEdit->toPlainText());
  //
  QFile dictionary("dictionary.txt");
  dictionary.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadWrite);
  QTextStream writeStream(&dictionary);
  writeStream.setCodec("UTF-8");
  //
  QStringList newDictionary;
  QString newRus;
  QString newEng;
  // Сохраняем русский и латинский вариант для последующего сравнения
  // на повторение в файле, а так же записываетм результат в файл.
  if (ui_->rusButton->isChecked()){
    newRus = ui_->firstTextEdit->toPlainText();
    newEng = ui_->secondTextEdit->toPlainText();
    writeStream << "\n" + newRus + "\n" + newEng;
  }
  else{
    newRus = ui_->secondTextEdit->toPlainText();
    newEng = ui_->firstTextEdit->toPlainText();
    writeStream << "\n" + newRus + "\n" +  newEng;
  }
  dictionary.close();
  //
  dictionary.open(QIODevice::ReadOnly | QIODevice::Text);
  writeStream.flush();
  writeStream.readLine();
  bool isRepeat = false;
  // Ищем повторения в файле и запоминаем неповторяющиеся пары.
  while (!writeStream.atEnd()) {
    QString rus = writeStream.readLine();
    QString eng = writeStream.readLine();

    if (((rus == newRus) || (eng == newEng))){
      if (!isRepeat){
        newDictionary.push_back("\n" + newRus);
        newDictionary.push_back("\n" + newEng);
        isRepeat = true;
      }
    } else{
      newDictionary.push_back("\n" + rus);
      newDictionary.push_back("\n" + eng);
    }
  }
  dictionary.close();
  // Очищаем полностью файл.
  dictionary.open(QIODevice::WriteOnly | QIODevice::Truncate);
  dictionary.close();
  // Полученные выше уникальные пары выводим в файл.
  dictionary.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadWrite);
  writeStream.flush();
  for (auto str : newDictionary){
    writeStream << str;
  }
  dictionary.close();
}

void transliteration::keyPressEvent(QKeyEvent *aEvent){
  // При нажатии на Enter будет выполняться перевод.
  if (aEvent->key() == Qt::Key_Return){
    TranslateButtonProcessing();
  }
}

QString transliteration::TestFunction(bool aIsDictionary, bool aIsRus, int aTranslateIndex, QString aText){
  // Устанавливаем нужный нам перевод.
  if (aIsRus){
    ui_->rusButton->setChecked(true);
  } else{
    ui_->engButton->setChecked(true);
  }
  // Проверяем, нужно ли использовать словарь.
  if (aIsDictionary){
      ui_->checkBox->setChecked(true);
  }
  // Устанавливаем метод перевода.
  ui_->comboBox->setCurrentIndex(aTranslateIndex);
  // Устанавливаем текст для перевода.
  ui_->firstTextEdit->setText(aText);
  // Вызов метода для транслитерации.
  TranslateButtonProcessing();
  return ui_->secondTextEdit->toPlainText();
}

transliteration::~transliteration(){
  delete ui_;
}
