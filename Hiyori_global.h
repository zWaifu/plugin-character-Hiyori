#ifndef HIYORI_GLOBAL_H
#define HIYORI_GLOBAL_H

#include <QtCore/qglobal.h>
#include "QTypesFormatter.h"

#if defined(HIYORI_LIBRARY)
#  define HIYORI_EXPORT Q_DECL_EXPORT
#else
#  define HIYORI_EXPORT Q_DECL_IMPORT
#endif

#endif // HIYORI_GLOBAL_H
