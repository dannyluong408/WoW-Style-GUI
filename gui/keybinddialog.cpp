#include "GUI/keybindialog.hpp"
#include "GUI/mainwindow.h"

KeybindDialog::KeybindDialog(QWidget *parent)
    : QFrame(parent)
{
    setGeometry(150,150,150,150);
    setObjectName("keybindDialog");
    setStyleSheet("border: 2px solid black;"
                  "background-color: white;");
    info = new QLabel(this);
    info->resize(150,150);
    info->setText("Press a Key Combination! Press (ESC) to cancel!");
    info->setAlignment(Qt::AlignCenter);
    info->setWordWrap(true);
    num = -1;
    count = 0;
    setFocus();
    grabKeyboard();
    grabMouse();
    show();
}

//possibly use QKeySequenceEdit in the future but probably not
void KeybindDialog::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Control || event->key() == Qt::Key_Shift || event->key() == Qt::Key_Alt || event->key() == Qt::Key_unknown) {
        event->ignore();
    }
    else if (event->key() == Qt::Key_Escape) {
        delete(this);
        return;
    }
    else {
        mod = event->modifiers();
        if (mod & Qt::ControlModifier ) buttonPress.append("Ctrl+");
        if (mod & Qt::ShiftModifier ) buttonPress.append("Shift+");
        if (mod & Qt::AltModifier ) buttonPress.append("Alt+");
        buttonPress.append(QKeySequence(event->key()).toString());
        qDebug() << "Abc:" << event->nativeScanCode() << event->key() << event->text();
        emit newBind(QKeySequence(buttonPress), num);
        qDebug() << "Dialog:" << QKeySequence(buttonPress).toString();
        delete(this);
        return;
    }
}
void KeybindDialog::mousePressEvent(QMouseEvent *mevent){
    if (mevent->button() == Qt::MidButton || mevent->button() == Qt::BackButton || mevent->button() == Qt::ForwardButton) {
        mod = mevent->modifiers();
        if (mod & Qt::ControlModifier ) buttonPress.append("Ctrl+");
        if (mod & Qt::ShiftModifier ) buttonPress.append("Shift+");
        if (mod & Qt::AltModifier ) buttonPress.append("Alt+");
        if (mevent->button() == Qt::MidButton) buttonPress.append("F33");
        if (mevent->button() == Qt::BackButton) buttonPress.append("F34");
        if (mevent->button() == Qt::ForwardButton) buttonPress.append("F35");

        qDebug() << QKeySequence(buttonPress).toString();
        qDebug() << mevent->button();
        qDebug() << buttonPress;
        //add if statement to only emit if cursor is in correct place
        emit newBind(QKeySequence(buttonPress), num);
        delete(this);
        return;
    }
}

void KeybindDialog::wheelEvent(QWheelEvent *wevent){
    mod = wevent->modifiers();
    if (mod & Qt::ControlModifier ){
        buttonPress.append("Ctrl+");
    }
    if (mod & Qt::ShiftModifier ){
        buttonPress.append("Shift+");
    }
    if (mod & Qt::AltModifier ){
        buttonPress.append("Alt+");
    }
    if (wevent->angleDelta().y() > 0 || wevent->angleDelta().x() > 0){
        buttonPress.append("F31");
    }
    else {
        buttonPress.append("F32");
    }

    qDebug() << QKeySequence(buttonPress).toString();
    qDebug() << wevent->angleDelta().x() << " + " << wevent->angleDelta().y();
    qDebug() << buttonPress;
    //add if statement to only emit if cursor is in correct place
    emit newBind(QKeySequence(buttonPress), num);
    delete(this);
    return;

}
