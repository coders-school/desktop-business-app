#ifndef DOCTORGRAPHICALINTERFACE_HPP
#define DOCTORGRAPHICALINTERFACE_HPP
#include <QAbstractTableModel>
#include <QString>
#include <QDate>
#include <QVector>
struct Appointment {
    QString firstName;
    QString lastName;
    QDate date;
    QString treatment;
    QString room;
};
class DoctorGraphicalInterface : public QAbstractTableModel {
    Q_OBJECT
public:
    explicit DoctorGraphicalInterface(QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE void addAppointment(const QString& firstName, const QString& lastName, const QDate& date, const QString& treatment, const QString& room);
private:
    QVector<Appointment> appointments;
};
#endif // DOCTORGRAPHICALINTERFACE_HPP
