#ifndef GEOSERVICEPROVIDERFACTORY_H
#define GEOSERVICEPROVIDERFACTORY_H
#include <QObject>
#include <QGeoServiceProviderFactory>

class GeoServiceProviderFactory : public QObject, public QGeoServiceProviderFactory
{
    Q_OBJECT
    Q_INTERFACES(QGeoServiceProviderFactory)

public:
    QGeoCodingManagerEngine*    createGeocodingManagerEngine    (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
    QGeoMappingManagerEngine*   createMappingManagerEngine      (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
    QGeoRoutingManagerEngine*   createRoutingManagerEngine      (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
    QPlaceManagerEngine*        createPlaceManagerEngine        (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;

};

#endif // GEOSERVICEPROVIDERFACTORY_H
