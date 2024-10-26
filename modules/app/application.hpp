#pragma once

#include <QObject>
#include <QUrl>
#include <qqml.h>

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);
};