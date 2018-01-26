#include "GeoServiceProviderFactory.h"

QGeoCodingManagerEngine* GeoServiceProviderFactory::createGeocodingManagerEngine(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    return NULL;
}

QGeoMappingManagerEngine* GeoServiceProviderFactory::createMappingManagerEngine(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    return NULL;
}

QGeoRoutingManagerEngine* GeoServiceProviderFactory::createRoutingManagerEngine(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    return NULL;
}

QPlaceManagerEngine* GeoServiceProviderFactory::createPlaceManagerEngine(
        const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    return NULL;
}

