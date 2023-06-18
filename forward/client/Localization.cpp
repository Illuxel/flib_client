#include "forward/client/Localization.hpp"

#include <QQmlApplicationEngine>
#include <QApplication>
#include <QLocale>

QTranslator* Localization::translator_ = nullptr;

QStringList Localization::localeList() const
{
    return {"English", "Ukrainian"};
}
QStringList Localization::countryList() const
{
    QStringList temp;
    QList<QLocale> locales = QLocale::matchingLocales(QLocale::AnyLanguage, QLocale::AnyScript, QLocale::AnyCountry);

    for (const auto& locale : locales)
    {
        temp.append(locale.countryToString(locale.country()));
    }

    return temp;
}

QString Localization::currentLocale() const
{
    return QLocale::languageToString(QLocale::system().language());
}

void Localization::changeLocale(QString const& language)
{
    auto lang_code = getLanguageCode(language);
    QLocale locale(lang_code);

    if (!translator_)
        translator_ = new QTranslator();

    QApplication::removeTranslator(translator_);

    if (!translator_->load(locale, "lang", "_", ":/langs"))
		return;

    QApplication::installTranslator(translator_);

    auto engine = qobject_cast<QQmlApplicationEngine *>(qmlEngine(this));

    if (engine)
        engine->retranslate();
}

QString Localization::getLanguageCode(QString const& displayName) const
{
    QList<QLocale> locales = QLocale::matchingLocales(QLocale::AnyLanguage, QLocale::AnyScript, QLocale::AnyCountry);

    for (auto const& locale : locales) {

        auto language = QLocale::languageToString(locale.language());

        if (language == displayName) {
            return locale.name();
        }
    }

    return QString();
}