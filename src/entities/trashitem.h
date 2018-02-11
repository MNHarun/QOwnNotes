#pragma once

#include <QDateTime>
#include <QSqlQuery>
#include <QFile>
#include <QUrl>
#include "notesubfolder.h"
#include "note.h"


class TrashItem {
public:
    explicit TrashItem();

    int getId();

    QString getFileName();

    static TrashItem fetch(int id);

    static QList<TrashItem> fetchAll(int limit = -1);

    bool store();

    friend QDebug operator<<(QDebug dbg, const TrashItem &trashItem);

    bool fileExists();

    bool exists();

    bool refetch();

    bool fillFromQuery(QSqlQuery query);

    bool removeNoteFile();

    bool remove(bool withFile = false);

    bool isFetched();

    QDateTime getCreated();

    static int countAll();

    QString fileBaseName(bool withFullName = false);

    NoteSubFolder getNoteSubFolder();

    void setNoteSubFolder(NoteSubFolder noteSubFolder);

    QString relativeNoteFilePath(QString separator = "");

    QString getNoteSubFolderPathData();

    qint64 getFileSize();

    static TrashItem trashItemFromQuery(QSqlQuery query);

    static bool deleteAll();

    bool fillFromId(int id);

    QString fullNoteFilePath();

    static bool add(Note note);

    static bool add(Note *note);

    void setNote(Note note);

    void setNote(Note *note);

    static TrashItem prepare(Note *note);

    bool doTrashing();

protected:
    int id;
    QString fileName;
    qint64 fileSize;
    QString noteSubFolderPathData;
    int noteSubFolderId;
    QDateTime created;
    QString _fullNoteFilePath;
};