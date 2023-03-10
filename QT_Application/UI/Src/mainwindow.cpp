#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    setWindowTitle("XML Tool");
    setWindowIcon(QIcon(":/icon/Icons/MainWindow.jpg"));

    setStyleSheet("MainWindow{background-color:rgb(255,255,255);}");

    for(int i=0;i<13;i++)
    {
        effect[i] = new QGraphicsDropShadowEffect();
        effect[i]->setBlurRadius(2);
        effect[i]->setXOffset(0.5);
        effect[i]->setYOffset(1);
        effect[i]->setColor(qRgba(0,0,0,1));
    }

    Buttons[0] = ui->pushButton_Browse;
    Buttons[1] = ui->pushButton_Validate;
    Buttons[2] = ui->pushButton_Format;
    Buttons[3] = ui->pushButton_JSON;
    Buttons[4] = ui->pushButton_Minify;
    Buttons[5] = ui->pushButton_Compress;
    Buttons[6] = ui->pushButton_Decompress;
    Buttons[7] = ui->pushButton_MostActive;
    Buttons[8] = ui->pushButton_MostInfluncer;
    Buttons[9] = ui->pushButton_MutualFollowers;
    Buttons[10] = ui->pushButton_2ndDegreeFollowers;
    Buttons[11] = ui->pushButton_PostSearch;
    Buttons[12] = ui->pushButton_SaveAs;
    for(int i=0;i<13;i++)
    {
        Buttons[i]->setStyleSheet(
                                    "QPushButton"
                                    "{"
                                     "background-color:rgb(100,200,255);border:none;"
                                     "margin-left: 0;"
                                     "float: none;"
                                     "font-weight: bolder;"
                                     "line-height: 20px;"
                                     "color: #333;"
                                     "text-align: center;"
                                     "vertical-align: middle;"
                                     "background-color: #f5f5f5;"
                                     "background-image: linear-gradient(to bottom,#fff,#e6e6e6);"
                                     "background-repeat: repeat-x;"
                                     "border: 1px solid #ccc;"
                                     "border-color: rgba(0,0,0,.1) rgba(0,0,0,.1) rgba(0,0,0,.25);"
                                     "border-bottom-color: #b3b3b3;"
                                     "border-radius: 4px;"
                                    "}"
                                    "QPushButton:hover,focus,active,disabled"
                                    "{"
                                        "background-color: #e6e6e6;"
                                     "}"
                                    "QPushButton:hover,focus"
                                    "{"
                                       "color: #333;"
                                       "text-decoration: none;"
                                       "background-position: 0 -15px;"
                                    "}"
                                    "QPushButton:focus"
                                    "{"
                                      "outline-offset: -2px;"
                                    "}"
                                   );
        Buttons[i]->setGraphicsEffect(effect[i]);
        Buttons[i]->setCursor(Qt::PointingHandCursor);

    }
    gEffect = new QGraphicsDropShadowEffect();
    gEffect->setBlurRadius(5);
    gEffect->setXOffset(0);
    gEffect->setYOffset(1);
    gEffect->setColor(qRgba(34,25,25,4));
    ui->groupBox->setGraphicsEffect(gEffect);
    ui->groupBox->setStyleSheet("GroupBox{background-color:rgb(255,255,255);}");

    XMLInput = new CodeEditor();
    ui->formLayout_Input->addWidget(XMLInput);

    XMLOutput = new CodeEditor();
    ui->formLayout_Output->addWidget(XMLOutput);


    QPixmap pix(":/icon/Icons/copy.png");
    for(int i=0;i<2;i++)
    {
        Copy[i] = new ClickableLabel();
        Copy[i]->setStyleSheet(
                             "ClickableLabel"
                             "{"
                                   "margin-right: 5px;"
                             "}"
                             );
        Copy[i]->setMouseTracking(true);
        Copy[i]->setCursor(Qt::PointingHandCursor);
        Copy[i]->setPixmap(pix.scaled(20,20,Qt::KeepAspectRatio));
        Copy[i]->setToolTip("Copy");
    }


    sample = new ClickableLabel();
    sample->setText("sample");
    sample->setStyleSheet(
                         "ClickableLabel"
                         "{"
                               "margin-right: 5px;"
                               "color: #08c;"
                               "text-align: center;"
                               "font-weight: bold;"
                               "font-size: 14px;"
                               "line-height: 20px;"
                               "text-decoration: underline;"
                               "font: 700 14pt \"Constantia\";"
                         "}"
                         );
    sample->setMouseTracking(true);
    sample->setCursor(Qt::PointingHandCursor);

    Delete = new ClickableLabel();
    Delete->setStyleSheet(
                         "ClickableLabel"
                         "{"
                               "margin-right: 5px;"
                         "}"
                         );
    Delete->setMouseTracking(true);
    Delete->setCursor(Qt::PointingHandCursor);
    QPixmap pic(":/icon/Icons/delete.png");
    Delete->setPixmap(pic.scaled(20,20,Qt::KeepAspectRatio));
    Delete->setToolTip("Delete");

    ui->horizontalLayout_16->addWidget(Copy[0]);
    ui->horizontalLayout_16->addWidget(sample);
    ui->horizontalLayout_16->addWidget(Delete);
    ui->horizontalLayout_17->addWidget(Copy[1]);

    XMLInputEffect = new QGraphicsDropShadowEffect();
    XMLInputEffect->setBlurRadius(2);
    XMLInputEffect->setXOffset(-1);
    XMLInputEffect->setYOffset(1);
    XMLInputEffect->setColor(qRgba(0,0,0,1));
    ui->groupBox_2->setGraphicsEffect(XMLInputEffect);

    XMLOutputEffect = new QGraphicsDropShadowEffect();
    XMLOutputEffect->setBlurRadius(2);
    XMLOutputEffect->setXOffset(1);
    XMLOutputEffect->setYOffset(1);
    XMLOutputEffect->setColor(qRgba(0,0,0,1));
    ui->groupBox_3->setGraphicsEffect(XMLOutputEffect);

    fileName = QDir::homePath();

    clip = QApplication::clipboard();

    //graph = new Graph();

    connect(Copy[0],SIGNAL(clicked()),this,SLOT(LeftCopy_clicked()));
    connect(sample,SIGNAL(clicked()),this,SLOT(Sample_clicked()));
    connect(Delete,SIGNAL(clicked()),this,SLOT(Delete_clicked()));
    connect(Copy[1],SIGNAL(clicked()),this,SLOT(RightCopy_clicked()));
}

QString MainWindow::read_file(QString& fileName)
{
    QFile file(fileName);
    file.open(QFile::ReadOnly |QFile::Text);
    QTextStream in(&file);
    QString text;
    text = in.readAll();
    file.close();
    return text;
}

void MainWindow::write_file(QString& fileName, QString& text)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }
    QTextStream out(&file);
    out << text << "\n";
    file.flush();
    file.close();
}


QString MainWindow::read_codeeditor(CodeEditor* editor)
{
    return editor->toPlainText();
}

void MainWindow::write_codeeditor(CodeEditor* editor, QString& text)
{
    editor->setPlainText(text);
}

void MainWindow::saveFile(QString& data,QString extension)
{
    QString dir = QFileDialog::getExistingDirectory(this, "Save Compressed File",fileName,QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    if (dir.isEmpty())
    {
       return;
    }
    else
    {
        QString filePath = dir + "/Compressed" + extension;
        write_file(filePath,data);
        QMessageBox::information(this,"Result","The new file is downloaded in " + filePath);
    }
}

QString MainWindow::getFile()
{
    QString filter = "Text File(*.txt) Hm File(*.hm)";
    QString filename = QFileDialog::getOpenFileName(this,"Decompress File",fileName,filter);
    QString text = read_file(filename);
    return text;
}

void MainWindow::show_progress(QString progressingVal)
{
    QLabel* label = new QLabel(progressingVal);
    label->setStyleSheet("QLabel{font: 700 14pt Constantia;font-weight: bolder;line-height: 20px;color: #333;}");
    int numTasks = 100000;
    QProgressDialog progress( progressingVal, QString(), 0,numTasks , this);
    progress.setMinimumDuration(0);
    progress.setWindowModality(Qt::WindowModal);
    progress.setWindowTitle(progressingVal + " Progress");
    progress.setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    progress.setLabel(label);
    progress.show();

    for (int i = 0; i < numTasks; i++)
    {
        progress.setValue(i);
    }
    progress.setValue(numTasks);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete XMLInput;
    delete XMLOutput;
    for(int i=0;i<2;i++)
        delete Copy[i];
    for(int i=0;i<13;i++)
    {
        delete Buttons[i];
        delete effect[i];
    }
    delete gEffect;
    delete sample;
    delete Delete;
}



void MainWindow::on_pushButton_Browse_clicked()
{
    QString filter = "XML File(*.xml) ;;  JSON File(*.json)";
    fileName = QFileDialog::getOpenFileName(this,"Open File",fileName,filter);
    QString text = read_file(fileName);
    write_codeeditor(XMLInput,text);
}


void MainWindow::on_pushButton_Validate_clicked()
{
    QString text = read_codeeditor(XMLInput);
    if(text.isEmpty())
    {
        QMessageBox::critical(this,"Result","No Input is found");
    }
    else
    {
       bool result =  error_detection(text.toStdString());
       if(result == true)
       {
           QMessageBox::information(this,"Result","Valid");
       }
       else
       {
           QString errorList = QString::fromStdString(error_list(text.toStdString()));
           QMessageBox::critical(this,"Result",errorList);
           QMessageBox::StandardButton answer = QMessageBox::question(this,"Result","Do you want to solve the error?",QMessageBox::Yes | QMessageBox::No);
           if(answer == QMessageBox::Yes)
           {
               QString solve = QString::fromStdString(error_correction(text.toStdString()));
               write_codeeditor(XMLOutput,solve);
           }
       }
    }
}


void MainWindow::on_pushButton_Format_clicked()
{
    QString text = read_codeeditor(XMLInput);
    if(text.isEmpty())
    {
        QMessageBox::critical(this,"Result","No Input is found");
    }
    else
    {
         QString output = QString::fromStdString(formatting(text.toStdString()));
         write_codeeditor(XMLOutput,output);
    }
}


void MainWindow::on_pushButton_Minify_clicked()
{
    QString text = read_codeeditor(XMLInput);
    if(text.isEmpty())
    {
        QMessageBox::critical(this,"Result","No Input is found");
    }
    else
    {
        //To convert from String to QString, use fromStdString
        //To convert from QString to String use toStdString()
        QString output = QString::fromStdString(xml_minifying(text.toStdString()));
        write_codeeditor(XMLOutput,output);
    }
}


void MainWindow::on_pushButton_JSON_clicked()
{
    QString text = read_codeeditor(XMLInput);
    if(text.isEmpty())
    {
        QMessageBox::critical(this,"Result","No Input is found");
    }
    else
    {
        QString output = QString::fromStdString(xmlToJson(text.toStdString()));
        write_codeeditor(XMLOutput,output);
    }
}

QString fromVector(const QVector<uchar> vector)
{
    return QString::fromUtf8(reinterpret_cast<const char*>(vector.data()), vector.size());
}

void MainWindow::on_pushButton_Compress_clicked()
{
    QString text = read_codeeditor(XMLInput);
    if(text.isEmpty())
    {
        QMessageBox::critical(this,"Result","No Input is found");
    }
    else
    {
        vector<unsigned char> compressedVector = compress(text.toStdString());
        QVector<unsigned char> qv;
        qv.reserve(compressedVector.size());
        for (int element : compressedVector)
            qv.append(element);
        QString compressedData =  QString::fromUtf8(reinterpret_cast<const char*>(qv.data()), qv.size());
        write_codeeditor(XMLOutput,compressedData);
        /*show_progress("Compressing:");
        saveFile(compressedData,".hm");*/
    }
}


void MainWindow::on_pushButton_Decompress_clicked()
{
    QString compressedData = getFile();
    QString decompressedData = QString::fromStdString(decompress(compressedData.toStdString()));
    show_progress("Decompressing:");
    int type = detect_type(compressedData.toStdString());
    switch(type)
    {
    case 0:
        saveFile(decompressedData,".xml");
        break;
    case 1:
        saveFile(decompressedData,".json");
        break;
    case 2:
        saveFile(decompressedData,".txt");
        break;
    }
}


void MainWindow::on_pushButton_MostActive_clicked()
{
    /*QString text = read_codeeditor(XMLInput);
    if(text.isEmpty())
    {
        QMessageBox::critical(this,"Most Active","No Input is found");
    }
    else
    {
        graph->extract_data(text.toStdString());
        text = "";
        vector<string> outputVector = graph->get_most_active();
        for(string element:outputVector)
        {
            text = text + QString::fromStdString(element) + "";
        }
         QMessageBox::information(this,"Most Active",text);
    }*/
}


void MainWindow::on_pushButton_MostInfluncer_clicked()
{
    /*QString text = read_codeeditor(XMLInput);
    if(text.isEmpty())
    {
        QMessageBox::critical(this,"Most Influncer","No Input is found");
    }
    else
    {
        graph->extract_data(text.toStdString());
        text = "";
        vector<string> outputVector = graph->get_most_influncer();
        for(auto element:outputVector)
        {
            text = text + QString::fromStdString(element) + "\n";
        }
         QMessageBox::information(this,"Most Influncer",text);
    }*/
}

void MainWindow::on_pushButton_MutualFollowers_clicked()
{
    /*QString text = read_codeeditor(XMLInput);
    if(text.isEmpty())
    {
        QMessageBox::critical(this,"Mutual Followers","No Input is found");
    }
    else
    {
        graph->extract_data(text.toStdString());
        text = "";
        InputDialog dialog(this);
            if (dialog.exec() == QDialog::Accepted)
            {
                QString user1Id = dialog.getUser1Id();
                QString user2Id = dialog.getUser2Id();

                   vector<string> outputVector = graph->get_mutual_followers(user1Id.toInt(),user2Id.toInt());
                   text = "";
                   if(outputVector.empty())
                       QMessageBox::information(this,"Mutual Followers","No Mutual Followers");
                   else if(outputVector.size() == 1 && outputVector[0] == " ")
                   {
                       QMessageBox::critical(this,"Mutual Followers","ID is not found");
                   }
                   else
                   {
                       for(auto element:outputVector)
                       {
                           text = text + QString::fromStdString(element) + "\n";
                       }
                        QMessageBox::information(this,"Mutual Followers",text);
                   }

            }
    }*/
}


void MainWindow::on_pushButton_2ndDegreeFollowers_clicked()
{
    /*QString text = read_codeeditor(XMLInput);
    if(text.isEmpty())
    {
        QMessageBox::critical(this,"2nd Degree Folowers","No Input is found");
    }
    else
    {
        //graph->extract_data(text.toStdString());
        text = "";
        InputDialog dialog(this);
            if (dialog.exec() == QDialog::Accepted)
            {
                QString userId = dialog.getUser1Id();

                   vector<string> outputVector = graph->get_followers_suggestions(userId.toInt());
                   text = "";
                   if(outputVector.empty())
                       QMessageBox::information(this,"2nd Degree Folowers","No Suggestions");
                   else if(outputVector.size() == 1 && outputVector[0] == " ")
                   {
                       QMessageBox::critical(this,"2nd Degree Folowers","ID is not found");
                   }
                   else
                   {
                       for(auto element:outputVector)
                       {
                           text = text + QString::fromStdString(element) + "\n";
                       }
                        QMessageBox::information(this,"2nd Degree Folowers",text);
                   }

            }
    }*/
}


void MainWindow::on_pushButton_PostSearch_clicked()
{
    /*QString text = read_codeeditor(XMLInput);
    if(text.isEmpty())
    {
        QMessageBox::critical(this,"Post Search","No Input is found");
    }
    else
    {
        graph->extract_data(text.toStdString());
        text = "";
    }*/
}

void MainWindow::on_pushButton_SaveAs_clicked()
{
    QString filter = "XML File(*.xml) ;;  JSON File(*.json)";
    QString filePath = QFileDialog::getSaveFileName(this, "Save As",fileName,filter);
    if (fileName.isEmpty())
    {
       return;
    }
    else
    {
        QString text = read_codeeditor(XMLOutput);
        write_file(filePath,text);
    }
}

void MainWindow::LeftCopy_clicked()
{
    QString input = XMLInput->toPlainText();
    clip->setText(input);
    QMessageBox::information(this,"Result","Copy to the Clipboard");
}

void MainWindow::RightCopy_clicked()
{
    QString input = XMLOutput->toPlainText();
    clip->setText(input);
    QMessageBox::information(this,"Result","Copy to the Clipboard");
}

void MainWindow::Sample_clicked()
{
    QString filePath = ":/sample/sample/sample.xml";
    QString text = read_file(filePath);
    write_codeeditor(XMLInput,text);
}

void MainWindow::Delete_clicked()
{
 XMLInput->setPlainText("");
}

