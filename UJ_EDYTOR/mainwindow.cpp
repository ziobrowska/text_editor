// Joanna Ziobrowska

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QIcon>
#include <QFileDialog>
#include <QInputDialog>
#include <QTextCursor>
#include <QTextBlock>
#include <QTextEdit>
#include <QList>

#include "kmptextiterator.h"
#include "classinvertedtextiterator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    // wielkość okna
    ui->setupUi(this);
    resize(1100, height());

    // dodajemy przyciski
    newFileAction = ui->toolbar->addAction(QIcon(":/images/new.png"), "Nowy");
    openFileAction = ui->toolbar->addAction(QIcon(":/images/open.png"), "Otwórz");
    saveFileAction = ui->toolbar->addAction(QIcon(":/images/save.png"), "Zapisz");
    ui->toolbar->addSeparator();

    saveFileAsAction = ui->toolbar->addAction("Zapisz Jako");
    exitAction = ui->toolbar->addAction("Zakończ");
    ui->toolbar->addSeparator();

    copyTextAction = ui->toolbar->addAction("Kopiuj");
    pasteTextAction = ui->toolbar->addAction("Wklej");
    cutTextAction = ui->toolbar->addAction("Wytnij");
    ui->toolbar->addSeparator();

    findTextKMPAction = ui->toolbar->addAction("Znajdź");
    findTextInvertedIndexAction = ui->toolbar->addAction("Znajdź słowo");
    replaceTextAction = ui->toolbar->addAction("Zastąp");
    ui->toolbar->addSeparator();

    editRedoAction = ui->toolbar->addAction("Ponów");
    editUndoAction = ui->toolbar->addAction("Cofnij");
    ui->toolbar->addSeparator();

    goToLineAction = ui->toolbar->addAction("Idź do..");
    selectAllTextAction = ui->toolbar->addAction("Zaznacz wszystko");

    // linkujemy akcje do przycisków
    connect(newFileAction, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(saveFileAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(saveFileAsAction, SIGNAL(triggered()), this, SLOT(saveFileAs()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(exit()));

    connect(copyTextAction, SIGNAL(triggered()), this, SLOT(copyText()));
    connect(pasteTextAction, SIGNAL(triggered()), this, SLOT(pasteText()));
    connect(cutTextAction, SIGNAL(triggered()), this, SLOT(cutText()));

    connect(findTextInvertedIndexAction, SIGNAL(triggered()), this, SLOT(findTextInvertedIndex()));
    connect(findTextKMPAction, SIGNAL(triggered()), this, SLOT(findTextKMP()));
    connect(replaceTextAction, SIGNAL(triggered()), this, SLOT(replaceText()));

    connect(editRedoAction, SIGNAL(triggered()), this, SLOT(editRedo()));
    connect(editUndoAction, SIGNAL(triggered()), this, SLOT(editUndo()));
    connect(goToLineAction, SIGNAL(triggered()), this, SLOT(goToLine()));
    connect(selectAllTextAction, SIGNAL(triggered()), this, SLOT(selectAllText()));

    //ustawiamy skróty
    newFileAction->setShortcut(QKeySequence("Ctrl+N"));
    openFileAction->setShortcut(QKeySequence("Ctrl+O"));
    saveFileAction->setShortcut(QKeySequence("Ctrl+S"));
    saveFileAsAction->setShortcut(QKeySequence("Ctrl+Shift+S"));
    exitAction->setShortcut(QKeySequence("Ctrl+Q"));

    copyTextAction->setShortcut(QKeySequence("Ctrl+C"));
    pasteTextAction->setShortcut(QKeySequence("Ctrl+V"));
    cutTextAction->setShortcut(QKeySequence("Ctrl+X"));

    findTextInvertedIndexAction->setShortcut(QKeySequence("Ctrl+W"));
    findTextKMPAction->setShortcut(QKeySequence("Ctrl+F"));
    replaceTextAction->setShortcut(QKeySequence("Ctrl+R"));

    editRedoAction->setShortcut(QKeySequence("Ctrl+Y"));
    editUndoAction->setShortcut(QKeySequence("Ctrl+Z"));
    goToLineAction->setShortcut(QKeySequence("Ctrl+G"));
    selectAllTextAction->setShortcut(QKeySequence("Ctrl+A"));

    //dodajemy akcje
    addAction(newFileAction);
    addAction(openFileAction);
    addAction(saveFileAction);
    addAction(saveFileAsAction);
    addAction(exitAction);

    addAction(copyTextAction);
    addAction(pasteTextAction);
    addAction(cutTextAction);

    addAction(findTextInvertedIndexAction);
    addAction(findTextKMPAction);
    addAction(replaceTextAction);

    addAction(editRedoAction);
    addAction(editUndoAction);
    addAction(goToLineAction);
    addAction(selectAllTextAction);
}

MainWindow::~MainWindow(){
    // destruktor - usuwanie również akcji
    delete ui;

    delete newFileAction;
    delete openFileAction;
    delete saveFileAction;
    delete saveFileAsAction;
    delete exitAction;

    delete copyTextAction;
    delete pasteTextAction;
    delete cutTextAction;

    delete findTextInvertedIndexAction;
    delete findTextKMPAction;
    delete replaceTextAction;

    delete editRedoAction;
    delete editUndoAction;
    delete goToLineAction;
    delete selectAllTextAction;
}
void MainWindow::inform(bool status){
       qDebug() << status;
}

void MainWindow::redoText(){ // ponów
    ui->edit->redo();
}

void MainWindow::newFile(){ // nowy plik
    MainWindow * window = new MainWindow();
    openedWindows.append(window);
    window->setWindowTitle("UJ EDYTOR");
    window->show();
}

void MainWindow::openFile(){ // otworz plik
    QString fileName = QFileDialog::getOpenFileName(this, "Wybierz plik", QDir::homePath());
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QTextStream stream(&file);
        ui->edit->setPlainText(stream.readAll());
        file.close();
    }
}

void MainWindow::saveFile(){ // zapisz
    if (openedFileName.isEmpty()) {
        openedFileName = QFileDialog::getSaveFileName(this, "Wybierz plik", QDir::homePath());
    }

    if (!openedFileName.isEmpty()) {
        QFile file(openedFileName);
        file.open(QIODevice::WriteOnly);
        QTextStream stream(&file);
        stream << ui->edit->toPlainText();
        file.close();
    }
}

void MainWindow::saveFileAs(){// zapisz jako
    openedFileName = QFileDialog::getSaveFileName(this, "Wybierz plik", QDir::homePath());

    if (!openedFileName.isEmpty()) {
        QFile file(openedFileName);
        file.open(QIODevice::WriteOnly);
        QTextStream stream(&file);
        stream << ui->edit->toPlainText();
        file.close();
    }
}

void MainWindow::exit(){ // zakończ
    qApp->quit();
}

void MainWindow::copyText(){// kopiuj
    ui->edit->copy();
}

void MainWindow::pasteText(){//wklej
    ui->edit->paste();
}

void MainWindow::cutText(){ //wytnij
    ui->edit->cut();
}

void MainWindow::findTextInvertedIndex()
{
    InvertedTextIterator iter;
    findTextByIterator(&iter);
}

void MainWindow::findTextKMP(){ //znajdz
    KMPTextIterator iter;
    findTextByIterator(&iter);
}

void MainWindow::findTextByIterator(TextIterator * iter) {
    QString text = QInputDialog::getText(this, "Co chcesz wyszukać?", "Proszę wprowadź tekst: ");

    if (text.isEmpty()) {
        return;
    }

    int pos = 0;
    QList<QTextEdit::ExtraSelection> selections;
    QTextCharFormat format;
    format.setBackground(QBrush(Qt::lightGray));

    while (true) {
        pos = iter->getNext(ui->edit->toPlainText().toStdString(), text.toStdString(), pos);

        if (pos == -1) {
            break;
        }

        QTextCursor cursor = ui->edit->textCursor();
        cursor.setPosition(pos - 1);
        cursor.setPosition(pos - 1 + text.size(), QTextCursor::KeepAnchor);

        pos += text.size();

        QTextEdit::ExtraSelection selection;
        selection.cursor = cursor;
        selection.format = format;
        selections.append(selection);
    }

    ui->edit->setExtraSelections(selections);
}

void MainWindow::replaceText(){ // zastap
    QString text = QInputDialog::getText(this, "Co chcesz wyszukać?", "Proszę wprowadź tekst: ");

    if (text.isEmpty()) {
        return;
    }

    QString newText = QInputDialog::getText(this, "Na co chcesz go zastąpić?", "Proszę wprowadź tekst: ");

    if (newText.isEmpty()) {
        return;
    }

    KMPTextIterator iter;
    int pos = 0;

    while (true) {
        pos = iter.getNext(ui->edit->toPlainText().toStdString(), text.toStdString(), pos);

        if (pos == -1) {
            break;
        }

        QTextCursor cursor = ui->edit->textCursor();
        cursor.setPosition(pos - 1);
        cursor.setPosition(pos - 1 + text.size(), QTextCursor::KeepAnchor);
        cursor.insertText(newText);

        pos += newText.size();
    }
}

void MainWindow::editUndo(){ // cofnij
    ui->edit->undo();
}

void MainWindow::editRedo(){ // ponów
    ui->edit->redo();
}

void MainWindow::goToLine(){ // skocz do lini
    bool ok;
    int lineNumber = QInputDialog::getInt(
       this, "Skocz do lini", "Wpisz, do której lini przejść: ",
       1, 1, ui->edit->document()->blockCount(), 1, &ok
    ) - 1;
    if (ok) {
        QTextCursor cursor(ui->edit->document()->findBlockByLineNumber(lineNumber));
        ui->edit->setTextCursor(cursor);
     }
}

void MainWindow::selectAllText(){ // zaznacz wszystko
    ui->edit->selectAll();
}
