#include "ReceptionistGraphicalInterface.hpp"

ReceptionistGraphicalInterface::ReceptionistGraphicalInterface(QObject* parent) : QAbstractTableModel(parent)
{
}

int ReceptionistGraphicalInterface::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return appointments.size();
}

int ReceptionistGraphicalInterface::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 5;
}

QVariant ReceptionistGraphicalInterface::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    const Appointment& appointment = appointments[index.row()];
    switch (index.column())
    {
    case 0:
        return appointment.firstName;
    case 1:
        return appointment.lastName;
    case 2:
        return appointment.date.toString("yyyy-MM-dd");
    case 3:
        return appointment.treatment;
    case 4:
        return appointment.room;
    default:
        return QVariant();
    }
}

QVariant ReceptionistGraphicalInterface::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return "First Name";
        case 1:
            return "Last Name";
        case 2:
            return "Date";
        case 3:
            return "Treatment";
        case 4:
            return "Room";
        default:
            return QVariant();
        }
    }
    return QVariant();
}

void ReceptionistGraphicalInterface::addAppointment(const QString& firstName, const QString& lastName, const QDate& date,
                                              const QString& treatment, const QString& room)
{
    beginInsertRows(QModelIndex(), appointments.size(), appointments.size());
    appointments.append({firstName, lastName, date, treatment, room});
    endInsertRows();
}