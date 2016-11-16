#include "keybindmenu.hpp"

KeybindMenu::KeybindMenu(QWidget *parent)
    : QFrame(parent)
{
    setObjectName("keybindMenu");
    resize(450,450);
    move(600 - this->width()/2, 450 - this->height()/2);
    setStyleSheet("keybindMenu{"
                  "border: 2px solid black;"
                  "border-left: none}");

    scrollArea = new QScrollArea(this);

    mainFrame = new QFrame(this);
    mainFrame->setGeometry(0,0,430,2000);

    mainLayout = new QGridLayout(mainFrame);
    mainLayout->setMargin(10);
    mainLayout->setSpacing(10);

    mainLayout->setColumnMinimumWidth(0,(double)this->width()*0.4);
    mainLayout->setColumnMinimumWidth(0,(double)this->width()*0.3);
    mainLayout->setColumnMinimumWidth(0,(double)this->width()*0.3);

    QString objectName;
    //init signal mappers
    keybindMapperMain = new QSignalMapper(this);
    connect(keybindMapperMain,SIGNAL(mapped(int)),this,SLOT(setBindMain(int)));
    keybindMapperBackup = new QSignalMapper(this);
    connect(keybindMapperBackup,SIGNAL(mapped(int)),this,SLOT(setBindBackup(int)));

    //indexes for grid
    int i = 0, index = 0, sectionIndex = 0, buttonNum = 0;

    //column header labels
    for(i = 0; i<3; i++){
        header[i] = new QLabel(this);
        header[i]->setAlignment(Qt::AlignCenter);
        header[i]->setStyleSheet("font-size: 12px;"
                                 "font-weight: bold;");
    }
    header[0]->setText("Action");
    header[0]->setFixedHeight(25);
    header[1]->setText("Key 1");
    header[1]->setFixedHeight(25);
    header[2]->setText("Key 2");
    header[2]->setFixedHeight(25);
    mainLayout->addWidget(header[0],index,0);
    mainLayout->addWidget(header[1],index,1);
    mainLayout->addWidget(header[2],index,2);
    index++;

    //move section labels
    sectionHeader[sectionIndex] = new QLabel(this);
    sectionHeader[sectionIndex]->setAlignment(Qt::AlignCenter);
    sectionHeader[sectionIndex]->setText("Movement Options");
    sectionHeader[sectionIndex]->setStyleSheet("font-weight: bold;");
    sectionHeader[sectionIndex]->setFixedHeight(25);
    mainLayout->addWidget(sectionHeader[sectionIndex],index,0);
    index++;
    sectionIndex++;

    for (i = 0; i<7; i++){
        moveKeybindDesc[i] = new QLabel(this);
        moveKeybindDesc[i]->setText(moveKeybindDescName[i]);
        moveKeybindDesc[i]->setAlignment(Qt::AlignCenter);
        moveKeybindDesc[i]->setFixedHeight(25);

        moveKeybind[i] = new QPushButton(this);
        moveKeybind[i]->setFixedHeight(25);
        moveKeybind[i]->setStyleSheet("border: 2px solid black;");
        objectName = "moveKeybind" + i;
        moveKeybind[i]->setObjectName(objectName);
        connect(moveKeybind[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(moveKeybind[i],buttonNum);

        moveKeybindBackup[i] = new QPushButton(this);
        moveKeybindBackup[i]->setFixedHeight(25);
        moveKeybindBackup[i]->setStyleSheet("border: 2px solid black;");
        objectName = "moveKeybindBackup" + i;
        moveKeybindBackup[i]->setObjectName(objectName);
        connect(moveKeybindBackup[i],SIGNAL(clicked()),keybindMapperBackup,SLOT(map()));
        keybindMapperBackup->setMapping(moveKeybindBackup[i],buttonNum);

        mainLayout->addWidget(moveKeybindDesc[i],index,0);
        mainLayout->addWidget(moveKeybind[i],index,1);
        mainLayout->addWidget(moveKeybindBackup[i],index,2);
        index++;
        buttonNum++;
    }

    //misc section labels
    sectionHeader[sectionIndex] = new QLabel(this);
    sectionHeader[sectionIndex]->setAlignment(Qt::AlignCenter);
    sectionHeader[sectionIndex]->setText("Combat Options");
    sectionHeader[sectionIndex]->setStyleSheet("font-weight: bold;");
    sectionHeader[sectionIndex]->setFixedHeight(25);
    mainLayout->addWidget(sectionHeader[sectionIndex],index,0);
    index++;
    sectionIndex++;

    combatKeybindDesc = new QLabel(this);
    combatKeybindDesc->setText(combatKeybindDescName);
    combatKeybindDesc->setAlignment(Qt::AlignCenter);
    combatKeybindDesc->setFixedHeight(25);

    combatKeybind = new QPushButton(this);
    combatKeybind->setFixedHeight(25);
    combatKeybind->setStyleSheet("border: 2px solid black;");
    objectName = "combatKeybind";
    combatKeybind->setObjectName(objectName);
    connect(combatKeybind,SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
    keybindMapperMain->setMapping(combatKeybind,buttonNum);

    combatKeybindBackup = new QPushButton(this);
    combatKeybindBackup->setFixedHeight(25);
    combatKeybindBackup->setStyleSheet("border: 2px solid black;");
    objectName = "combatKeybindBackup";
    combatKeybindBackup->setObjectName(objectName);
    connect(combatKeybindBackup,SIGNAL(clicked()),keybindMapperBackup,SLOT(map()));
    keybindMapperBackup->setMapping(combatKeybindBackup,buttonNum);


    mainLayout->addWidget(combatKeybindDesc,index,0);
    mainLayout->addWidget(combatKeybind,index,1);
    mainLayout->addWidget(combatKeybindBackup,index,2);
    index++;
    buttonNum++;


    //targeting section labels
    sectionHeader[sectionIndex] = new QLabel(this);
    sectionHeader[sectionIndex]->setAlignment(Qt::AlignCenter);
    sectionHeader[sectionIndex]->setText("Targeting Options");
    sectionHeader[sectionIndex]->setStyleSheet("font-weight: bold;");
    sectionHeader[sectionIndex]->setFixedHeight(25);
    mainLayout->addWidget(sectionHeader[sectionIndex],index,0);
    index++;
    sectionIndex++;

    for (i = 0; i<30; i++){
        targetingKeybindDesc[i] = new QLabel(this);
        targetingKeybindDesc[i]->setText(targetingKeybindDescName[i]);
        targetingKeybindDesc[i]->setAlignment(Qt::AlignCenter);
        targetingKeybindDesc[i]->setFixedHeight(25);

        targetingKeybind[i] = new QPushButton(this);
        targetingKeybind[i]->setFixedHeight(25);
        targetingKeybind[i]->setStyleSheet("border: 2px solid black;");
        objectName = "targetingKeybind";
        targetingKeybind[i]->setObjectName(objectName);
        connect(targetingKeybind[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(targetingKeybind[i],buttonNum);

        targetingKeybindBackup[i] = new QPushButton(this);
        targetingKeybindBackup[i]->setFixedHeight(25);
        targetingKeybindBackup[i]->setStyleSheet("border: 2px solid black;");
        objectName = "targetingKeybindBackup";
        targetingKeybindBackup[i]->setObjectName(objectName);
        connect(targetingKeybindBackup[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(targetingKeybindBackup[i],buttonNum);

        mainLayout->addWidget(targetingKeybindDesc[i],index,0);
        mainLayout->addWidget(targetingKeybind[i],index,1);
        mainLayout->addWidget(targetingKeybindBackup[i],index,2);
        index++;
        buttonNum++;
    }

    //camera section labels
    sectionHeader[sectionIndex] = new QLabel(this);
    sectionHeader[sectionIndex]->setAlignment(Qt::AlignCenter);
    sectionHeader[sectionIndex]->setText("Camera Options");
    sectionHeader[sectionIndex]->setStyleSheet("font-weight: bold;");
    sectionHeader[sectionIndex]->setFixedHeight(25);
    mainLayout->addWidget(sectionHeader[sectionIndex],index,0);
    index++;
    sectionIndex++;

    for (i = 0; i<3; i++){
        cameraKeybindDesc[i] = new QLabel(this);
        cameraKeybindDesc[i]->setText(cameraKeybindDescName[i]);
        cameraKeybindDesc[i]->setAlignment(Qt::AlignCenter);
        cameraKeybindDesc[i]->setFixedHeight(25);

        cameraKeybind[i] = new QPushButton(this);
        cameraKeybind[i]->setFixedHeight(25);
        cameraKeybind[i]->setStyleSheet("border: 2px solid black;");
        objectName = "cameraKeybind"+i;
        cameraKeybind[i]->setObjectName(objectName);
        connect(cameraKeybind[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(cameraKeybind[i],buttonNum);

        cameraKeybindBackup[i] = new QPushButton(this);
        cameraKeybindBackup[i]->setFixedHeight(25);
        cameraKeybindBackup[i]->setStyleSheet("border: 2px solid black;");
        objectName = "cameraKeybindBackup";
        cameraKeybindBackup[i]->setObjectName(objectName);
        connect(cameraKeybindBackup[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(cameraKeybindBackup[i],buttonNum);

        mainLayout->addWidget(cameraKeybindDesc[i],index,0);
        mainLayout->addWidget(cameraKeybind[i],index,1);
        mainLayout->addWidget(cameraKeybindBackup[i],index,2);
        index++;
        buttonNum++;
    }

    //action button section labels
    sectionHeader[sectionIndex] = new QLabel(this);
    sectionHeader[sectionIndex]->setAlignment(Qt::AlignCenter);
    sectionHeader[sectionIndex]->setText("Action Button Options");
    sectionHeader[sectionIndex]->setStyleSheet("font-weight: bold;");
    sectionHeader[sectionIndex]->setFixedHeight(25);
    mainLayout->addWidget(sectionHeader[sectionIndex],index,0);
    index++;
    sectionIndex++;

    for (i = 0; i<10; i++){
        actionPrimaryButtonKeybindDesc[i] = new QLabel(this);
        actionPrimaryButtonKeybindDesc[i]->setText(actionPrimaryButtonKeybindDescName[i]);
        actionPrimaryButtonKeybindDesc[i]->setAlignment(Qt::AlignCenter);
        actionPrimaryButtonKeybindDesc[i]->setFixedHeight(25);

        actionPrimaryButtonKeybind[i] = new QPushButton(this);
        actionPrimaryButtonKeybind[i]->setFixedHeight(25);
        actionPrimaryButtonKeybind[i]->setStyleSheet("border: 2px solid black;");
        objectName = "actionPrimaryButtonKeybind"+i;
        actionPrimaryButtonKeybind[i]->setObjectName(objectName);
        connect(actionPrimaryButtonKeybind[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(actionPrimaryButtonKeybind[i],buttonNum);

        actionPrimaryButtonKeybindBackup[i] = new QPushButton(this);
        actionPrimaryButtonKeybindBackup[i]->setFixedHeight(25);
        actionPrimaryButtonKeybindBackup[i]->setStyleSheet("border: 2px solid black;");
        objectName = "actionPrimaryButtonKeybindBackup"+i;
        actionPrimaryButtonKeybindBackup[i]->setObjectName(objectName);
        connect(actionPrimaryButtonKeybindBackup[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(actionPrimaryButtonKeybindBackup[i],buttonNum);

        mainLayout->addWidget(actionPrimaryButtonKeybindDesc[i],index,0);
        mainLayout->addWidget(actionPrimaryButtonKeybind[i],index,1);
        mainLayout->addWidget(actionPrimaryButtonKeybindBackup[i],index,2);
        index++;
        buttonNum++;
    }

    for (i = 0; i<10; i++){
        actionSecondaryButtonKeybindDesc[i] = new QLabel(this);
        actionSecondaryButtonKeybindDesc[i]->setText(actionSecondaryButtonKeybindDescName[i]);
        actionSecondaryButtonKeybindDesc[i]->setAlignment(Qt::AlignCenter);
        actionSecondaryButtonKeybindDesc[i]->setFixedHeight(25);

        actionSecondaryButtonKeybind[i] = new QPushButton(this);
        actionSecondaryButtonKeybind[i]->setFixedHeight(25);
        actionSecondaryButtonKeybind[i]->setStyleSheet("border: 2px solid black;");
        objectName = "actionSecondaryButtonKeybind"+i;
        actionSecondaryButtonKeybind[i]->setObjectName(objectName);
        connect(actionSecondaryButtonKeybind[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(actionSecondaryButtonKeybind[i],buttonNum);

        actionSecondaryButtonKeybindBackup[i] = new QPushButton(this);
        actionSecondaryButtonKeybindBackup[i]->setFixedHeight(25);
        actionSecondaryButtonKeybindBackup[i]->setStyleSheet("border: 2px solid black;");
        objectName = "actionSecondaryButtonKeybindBackup"+i;
        actionSecondaryButtonKeybindBackup[i]->setObjectName(objectName);
        connect(actionSecondaryButtonKeybindBackup[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(actionSecondaryButtonKeybindBackup[i],buttonNum);

        mainLayout->addWidget(actionSecondaryButtonKeybindDesc[i],index,0);
        mainLayout->addWidget(actionSecondaryButtonKeybind[i],index,1);
        mainLayout->addWidget(actionSecondaryButtonKeybindBackup[i],index,2);
        index++;
        buttonNum++;
    }

    //interface section labels
    sectionHeader[sectionIndex] = new QLabel(this);
    sectionHeader[sectionIndex]->setAlignment(Qt::AlignCenter);
    sectionHeader[sectionIndex]->setText("Interface Options");
    sectionHeader[sectionIndex]->setStyleSheet("font-weight: bold;");
    sectionHeader[sectionIndex]->setFixedHeight(25);
    mainLayout->addWidget(sectionHeader[sectionIndex],index,0);
    index++;
    sectionIndex++;

    for (i = 0; i<8; i++){
        interfaceKeybindDesc[i] = new QLabel(this);
        interfaceKeybindDesc[i]->setText(interfaceKeybindDescName[i]);
        interfaceKeybindDesc[i]->setAlignment(Qt::AlignCenter);
        interfaceKeybindDesc[i]->setFixedHeight(25);

        interfaceKeybind[i] = new QPushButton(this);
        interfaceKeybind[i]->setFixedHeight(25);
        interfaceKeybind[i]->setStyleSheet("border: 2px solid black;");
        objectName = "interfaceKeybind"+i;
        interfaceKeybind[i]->setObjectName(objectName);
        connect(interfaceKeybind[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(interfaceKeybind[i],buttonNum);

        interfaceKeybindBackup[i] = new QPushButton(this);
        interfaceKeybindBackup[i]->setFixedHeight(25);
        interfaceKeybindBackup[i]->setStyleSheet("border: 2px solid black;");
        objectName = "interfaceKeybindBackup"+i;
        interfaceKeybindBackup[i]->setObjectName(objectName);
        connect(interfaceKeybindBackup[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(interfaceKeybindBackup[i],buttonNum);

        mainLayout->addWidget(interfaceKeybindDesc[i],index,0);
        mainLayout->addWidget(interfaceKeybind[i],index,1);
        mainLayout->addWidget(interfaceKeybindBackup[i],index,2);
        index++;
        buttonNum++;
    }

    //chat section labels
    sectionHeader[sectionIndex] = new QLabel(this);
    sectionHeader[sectionIndex]->setAlignment(Qt::AlignCenter);
    sectionHeader[sectionIndex]->setText("Chat Options");
    sectionHeader[sectionIndex]->setStyleSheet("font-weight: bold;");
    sectionHeader[sectionIndex]->setFixedHeight(25);
    mainLayout->addWidget(sectionHeader[sectionIndex],index,0);
    index++;
    sectionIndex++;

    for (i = 0; i<3; i++){
        chatKeybindDesc[i] = new QLabel(this);
        chatKeybindDesc[i]->setText(chatKeybindDescName[i]);
        chatKeybindDesc[i]->setAlignment(Qt::AlignCenter);
        chatKeybindDesc[i]->setFixedHeight(25);

        chatKeybind[i] = new QPushButton(this);
        chatKeybind[i]->setFixedHeight(25);
        chatKeybind[i]->setStyleSheet("border: 2px solid black;");
        objectName = "chatKeybind"+i;
        chatKeybind[i]->setObjectName(objectName);
        connect(chatKeybind[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(chatKeybind[i],buttonNum);

        chatKeybindBackup[i] = new QPushButton(this);
        chatKeybindBackup[i]->setFixedHeight(25);
        chatKeybindBackup[i]->setStyleSheet("border: 2px solid black;");
        objectName = "chatKeybindBackup"+i;
        chatKeybindBackup[i]->setObjectName(objectName);
        connect(chatKeybindBackup[i],SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
        keybindMapperMain->setMapping(chatKeybindBackup[i],buttonNum);

        mainLayout->addWidget(chatKeybindDesc[i],index,0);
        mainLayout->addWidget(chatKeybind[i],index,1);
        mainLayout->addWidget(chatKeybindBackup[i],index,2);
        index++;
        buttonNum++;
    }

    //misc section labels
    sectionHeader[sectionIndex] = new QLabel(this);
    sectionHeader[sectionIndex]->setAlignment(Qt::AlignCenter);
    sectionHeader[sectionIndex]->setText("Misc Options");
    sectionHeader[sectionIndex]->setStyleSheet("font-weight: bold;");
    sectionHeader[sectionIndex]->setFixedHeight(25);
    mainLayout->addWidget(sectionHeader[sectionIndex],index,0);
    index++;
    sectionIndex++;

    miscKeybindDesc = new QLabel(this);
    miscKeybindDesc->setText(miscKeybindDescName);
    miscKeybindDesc->setAlignment(Qt::AlignCenter);
    miscKeybindDesc->setFixedHeight(25);

    miscKeybind = new QPushButton(this);
    miscKeybind->setFixedHeight(25);
    miscKeybind->setStyleSheet("border: 2px solid black;");
    objectName = "miscKeybind"+i;
    miscKeybind->setObjectName(objectName);
    connect(miscKeybind,SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
    keybindMapperMain->setMapping(miscKeybind,buttonNum);

    miscKeybindBackup = new QPushButton(this);
    miscKeybindBackup->setFixedHeight(25);
    miscKeybindBackup->setStyleSheet("border: 2px solid black;");
    objectName = "miscKeybindBackup"+i;
    miscKeybindBackup->setObjectName(objectName);
    connect(miscKeybindBackup,SIGNAL(clicked()),keybindMapperMain,SLOT(map()));
    keybindMapperMain->setMapping(miscKeybindBackup,buttonNum);

    mainLayout->addWidget(miscKeybindDesc,index,0);
    mainLayout->addWidget(miscKeybind,index,1);
    mainLayout->addWidget(miscKeybindBackup,index,2);
    index++;
    buttonNum++;

    //second frame stuff
    secondFrame = new QFrame(this);
    secondFrame->setGeometry(0,350,450,100);
    secondFrame->setStyleSheet("border: 2px solid black;");

    //turn it all into a scroll area
    scrollArea->setWidget(mainFrame);
    scrollArea->setGeometry(0,0,450,350);


}

void KeybindMenu::setBindMain(int num){
    /* design
    popup msg to ask for keybind change
    use event/keyfilter to capture sequence
    emit new keybind back to mainwindow to update
    close window
    */

    if(this->findChild<KeybindDialog*>("keybindDialog")){
        qDebug() << "One is open right now";
        return;
    }
    emit disableShortcuts();
    KeybindDialog *keybindPrompt = new KeybindDialog(this);
    connect(keybindPrompt,SIGNAL(destroyed(QObject*)),this,SIGNAL(enableShortcuts()));

    qDebug() << num;
    if(num < 0){
        qDebug() << "Error";
    }
    else if(num < 7){
        qDebug() << "Setup Move";
    }
    else if(num == 7){
        qDebug() << "Setup Combat";
    }
    else if(num < 38){
        qDebug() << "Setup Targeting";
    }
    else if(num < 41){
        qDebug() << "Setup Camera";
    }
    else if(num < 51){
        qDebug() << "Setup Action Primary";
    }
    else if(num < 61){
        qDebug() << "Setup Action Secondary";
    }
    else if(num < 69){
        qDebug() << "Setup Interface";
    }
    else if(num < 72){
        qDebug() << "Setup Chat";
    }
    else if(num == 72){
        qDebug() << "Setup Misc";
    }
}

void KeybindMenu::setBindBackup(int num){
    qDebug() << num;
    if(num < 0){
        qDebug() << "Error";
    }
    else if(num < 7){
        qDebug() << "Setup Move Backup";
    }
    else if(num == 7){
        qDebug() << "Setup Combat Backup";
    }
    else if(num < 38){
        qDebug() << "Setup Targeting Backup";
    }
    else if(num < 41){
        qDebug() << "Setup Camera Backup";
    }
    else if(num < 51){
        qDebug() << "Setup Action Primary Backup";
    }
    else if(num < 61){
        qDebug() << "Setup Action Secondary Backup";
    }
    else if(num < 69){
        qDebug() << "Setup Interface Backup";
    }
    else if(num < 72){
        qDebug() << "Setup Chat Backup";
    }
    else if(num == 72){
        qDebug() << "Setup Misc Backup";
    }
}

void KeybindMenu::updateKeybinds(QString *shortcut){
    int i,index = 0;

    for(i=0; i<7; i++){
        moveKeybind[i]->setText(shortcut[index]);
        index++;
    }

    combatKeybind->setText(shortcut[index]);
    index++;

    for(i=0; i<30; i++){
        targetingKeybind[i]->setText(shortcut[index]);
        index++;
    }
    for(i=0; i<3; i++){
        cameraKeybind[i]->setText(shortcut[index]);
        index++;
    }
    for(i=0; i<10; i++){
        actionPrimaryButtonKeybind[i]->setText(shortcut[index]);
        index++;
    }
    for(i=0; i<10; i++){
        actionSecondaryButtonKeybind[i]->setText(shortcut[index]);
        index++;
    }
    for(i=0; i<8; i++){
        interfaceKeybind[i]->setText(shortcut[index]);
        index++;
    }
    for(i=0; i<3; i++){
        chatKeybind[i]->setText(shortcut[index]);
        index++;
    }

    miscKeybind->setText(shortcut[index]);
}