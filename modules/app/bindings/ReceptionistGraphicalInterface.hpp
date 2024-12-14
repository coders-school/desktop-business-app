#pragma once
#include <QAbstractTableModel>
#include <QDate>
#include <QString>
#include <QVector>

#include "DoctorGraphicalInterface.hpp"


class ReceptionistGraphicalInterface : public QAbstractTableModel
{
    Q_OBJECT
  public:
    explicit ReceptionistGraphicalInterface(QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE void addAppointment(const QString& firstName, const QString& lastName, const QDate& date,
                                    const QString& treatment, const QString& room);

  private:
    QVector<Appointment> appointments;
};