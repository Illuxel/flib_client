#include "Style.hpp"

#include <QQuickStyle>

QString Style::currentStyle() const
{
   return QQuickStyle::name();
}
QStringList Style::supportedStyles() const
{
   QStringList builtInStyles = { 
      QLatin1String("Basic"), 
      QLatin1String("Fusion"),
      QLatin1String("Imagine"), 
      QLatin1String("Material"), 
      QLatin1String("Universal") 
   };

#if defined(Q_OS_MACOS)
   builtInStyles << QLatin1String("macOS");
   builtInStyles << QLatin1String("iOS");
#elif defined(Q_OS_IOS)
   builtInStyles << QLatin1String("iOS");
#elif defined(Q_OS_WINDOWS)
   builtInStyles << QLatin1String("Windows");   
#endif

   return builtInStyles;
}

void Style::changeStyle(QString const& name)
{
   QQuickStyle::setStyle(name);
}