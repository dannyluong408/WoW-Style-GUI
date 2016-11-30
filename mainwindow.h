#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include <QHostInfo>
#include <QDebug>
#include <QtGlobal>
#include <time.h>
#include "ui_mainwindow.h"
#include "actionbar.h"
#include "dragpushbutton.h"
#include "actionbar.h"
#include "bufficon.h"
#include "targetbuffframe.hpp"
#include "playerbuffframe.hpp"
#include "unitframe.h"
#include "progressbar.h"
#include "chatframe.hpp"
#include "spellbook.h"
#include "gamemenu.hpp"
#include "guildframe.hpp"
#include "guildframe2.hpp"
#include "honorframe.hpp"
#include "partyframe.hpp"
#include "keybindmenu.hpp"
#include "menubar.h"
#include "options.hpp"
#include "miscenum.hpp"
#include <QFlags>
#include <cassert>

#define KEYBINDCOUNT 73

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadImage(const QString &path);
    void resizeEvent(QResizeEvent *event);
    void initDefaultKeybinds();
    void initDefaultActionbars();
    void initKeybinds();
    void loadActionBars();

    void keyPressEvent(QKeyEvent *event);

    //keybind functions
    void movePlayer(int direction);
    void togglePane(int pane);

    void toggleAttack();
    void targetingBind(int target);
    void cameraBind(int option);
    void toggleChat();
    void whisper(int type);
    void screenshot();

    //void mousePressEvent(QMouseEvent *mevent);
    void wheelEvent(QWheelEvent *wevent);
    void mousePressEvent(QMouseEvent *mevent);

public slots:
    void openOption(QString name);
    void disableShortcuts();
    void enableShortcuts();
    void newBindRecv(QKeySequence newKeybind, int num);
    void saveKeybinds();
    void defaultKeybinds();
    void saveActionBars();

private slots:
    void castSpell(int buttonPos);
    void login();
    void update();
    void lookedUp(const QHostInfo &host);
    //keybind slots
    void keybindSlot(int id);

signals:
    void newSize(QSize newSize);
    void toggleSpellbook();
    void pushKeybinds(QString *keybinds);

private:
    void initializeKeyBinds();
    //void keyPressEvent(QKeyEvent *event);
    Ui::MainWindow *ui;
    QTimer timer;

    //login stuff
    QWidget *loginScreen;
    QPushButton *loginButton;

    //core widgets
    ActionBar *actionBar[2];
    int numBars;
    UnitFrame *playerFrame,*targetFrame;
    PartyFrame *partyFrame;
    PlayerBuffFrame *playerBuff,*playerDebuff;
    TargetBuffFrame *targetBuff,*targetDebuff;
    ChatFrame *chatFrame;
    Menubar *menuBar;
    SpellBook *spellBook;
    GuildFrame2 *guildFrame;
    HonorFrame *honorFrame;
    GameMenu *gameMenu; //pops up when u hit esc
    OptionsFrame *optionsMenu; //pops up after u click options

    QString keybindString[73];
    QShortcut *shortcut[73];
    QSignalMapper *keybindMapper;

};

#endif // MAINWINDOW_H
