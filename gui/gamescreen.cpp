#include "GUI/gamescreen.hpp"
#include "GUI/mainwindow.h"

GameScreen::GameScreen(QWidget *parent)
    : QWidget(parent)
{

}


uint32_t GameScreen::getCursorID(){
    MainWindow *info = (MainWindow*)parent();
    qDebug() << "Grabbing GS ID:" << info->cursorID;
    return info->cursorID;
}


void GameScreen::dragEnterEvent(QDragEnterEvent *event){
    event->accept();
}
void GameScreen::dropEvent(QDropEvent *event){
    qDebug() << "DroppedGS :)";
}