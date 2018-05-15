// Joanna Ziobrowska

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QVector>

#include "textiterator.h"

namespace Ui {

class MainWindow;

}

class MainWindow : public QMainWindow{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void inform(bool status);
    void redoText();

    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void exit();

    void copyText();
    void pasteText();
    void cutText();

    void findTextInvertedIndex();
    void findTextKMP();
    void replaceText();

    void editUndo();
    void editRedo();
    void goToLine();
    void selectAllText();

    void findTextByIterator(TextIterator * iter);


private:
    Ui::MainWindow *ui;

    QAction * newFileAction;
    QAction * openFileAction;
    QAction * saveFileAction;
    QAction * saveFileAsAction;
    QAction * exitAction;

    QAction * copyTextAction;
    QAction * pasteTextAction;
    QAction * cutTextAction;

    QAction * findTextInvertedIndexAction;
    QAction * findTextKMPAction;
    QAction * replaceTextAction;

    QAction * editUndoAction;
    QAction * editRedoAction;
    QAction * goToLineAction;
    QAction * selectAllTextAction;

    QVector<MainWindow*> openedWindows;

    QString openedFileName;
};

#endif // MAINWINDOW_H
