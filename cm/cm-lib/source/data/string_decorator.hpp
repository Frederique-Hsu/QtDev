/*!
 *  \file       string_decorator.hpp
 *  \brief      Derived class for string properties
 *
 */


#ifndef STRING_DECORATOR_HPP
#define STRING_DECORATOR_HPP

    #include "data_decorator.hpp"

    namespace cm
    {
    namespace data
    {
        class CM_LIB_EXPORT StringDecorator : public DataDecorator
        {
            Q_OBJECT

            Q_PROPERTY(QString ui_value READ value WRITE setValue NOTIFY valueChanged)
        public:
            StringDecorator(Entity* parent_entity = nullptr,
                            const QString& key = "SomeItemKey",
                            const QString& label = "",
                            const QString& value = "");
            ~StringDecorator();

        public:
            StringDecorator& setValue(const QString& value);
            const QString& value() const;

            QJsonValue jsonValue() const override;
            void update(const QJsonObject& json_object) override;

        signals:
            void valueChanged();

        private:
            class Implementation;
            QScopedPointer<Implementation> m_implementor;
        };

    }   // end namespace data
    }   // end namespace cm


#endif  /* STRING_DECORATOR_HPP */
