/*!
 *  \file       canvas.hpp
 *  \brief
 *
 */


#ifndef CANVAS_HPP
#define CANVAS_HPP

    #include <QWidget>

    namespace Ui
    {
        class Canvas;
    }

    class Canvas : public QWidget
    {
        Q_OBJECT
    public:
        explicit Canvas(QWidget *parent = nullptr);
        ~Canvas();
    protected:
        void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;
    private:
        Ui::Canvas* ui;
    };

#endif  /* CANVAS_HPP */
