//
// Created by fangl on 2023/6/6.
//

#ifndef HW1_OGLMANAGER_H
#define HW1_OGLMANAGER_H

#include <QVector2D>
#include <QVector3D>
#include <QMatrix4x4>

#include <QDebug>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions_3_3_Core>

#include <QKeyEvent>
#include <QMouseEvent>

#include "Shader.h"


class OGLManager : public QOpenGLWidget {
public:
    explicit OGLManager(QWidget *parent = nullptr, int width = 200, int height = 200);
    ~OGLManager() override = default;

    // data functions
    void clearCanvas();
    void resolutionChange(int res);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    QOpenGLFunctions_3_3_Core *core;

    std::unique_ptr<Shader> pointShader;
    std::unique_ptr<Shader> gridShader;
    std::unique_ptr<Shader> curveShader;


};


#endif //HW1_OGLMANAGER_H
