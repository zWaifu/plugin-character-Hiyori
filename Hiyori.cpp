#include <QFile>
#include <QDir>


#include "AzWaifuEngine.h"
#include "Hiyori.h"

Hiyori::Hiyori()
{
}

void Hiyori::initialize(QSharedPointer<const AzWaifuEngine> engine)
{
    _engine = engine;
}

const QString Hiyori::_modelName = "桃瀬ひより";
const QString Hiyori::_modelFileName = "Hiyori";
const QUuid Hiyori::_modelId = QUuid("{2b3bf2f8-66a6-4512-bbf2-24c6bdd5d483}");

QString Hiyori::modelName() const
{
    return _modelName;
}

QString Hiyori::modelFileName() const
{
    return _modelFileName;
}

QByteArray Hiyori::loadFile(const QString &relativePath) const
{
    auto zlogger = _engine->logger();
    static const QDir rootPath = QDir(":/characters/桃瀬ひより/live2drc");
    QFileInfo fileInfo(rootPath, relativePath);
    zlogger->debug("loading file: {} ", relativePath);
    QFile file(fileInfo.absoluteFilePath());
    bool opened = file.open(QIODevice::ReadOnly);
    if (!opened) {
        zlogger->critical("failed to open file {}", relativePath);
        return QByteArray(0);
    } else {
        QByteArray bytes = file.readAll();
        zlogger->debug("loaded file {}", relativePath);
        return bytes;
    }
}

QUuid Hiyori::id() const
{
    return _modelId;
}
