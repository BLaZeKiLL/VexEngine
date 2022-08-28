#pragma once

#include "Vex/Math.h"

class TransformData final
{
private:
//    glm::mat4 m_Transform;

    glm::vec3 m_Position;
    glm::vec3 m_Axis;
    float m_Rotation;

public:
    TransformData(const glm::vec3& position, const glm::vec3& axis, float rotation);

    glm::mat4 GetTransform() const;

    void RenderUI();

    inline const glm::vec3& GetPosition() const { return m_Position; }
    inline const glm::vec3& GetAxis() const { return m_Axis; }
    inline const float GetRotation() const { return m_Rotation; }
};

class LightData final
{
private:
    glm::vec3 m_Position;
    glm::vec3 m_Color;

public:
    LightData(const glm::vec3& position, const glm::vec3& color);

    void RenderUI();

    inline const glm::vec3& GetPosition() const { return m_Position; }
    inline const glm::vec3& GetColor() const { return m_Color; }
};

class MaterialData final
{
private:
    glm::vec4 m_BaseColor;
    float m_AmbientStrength;
    float m_SpecularStrength;
    int m_SpecularShine;

public:
    MaterialData(const glm::vec4& baseColor, float ambientStrength, float specularStrength, int specularShine);

    void RenderUI();

    inline const glm::vec4& GetBaseColor() const { return m_BaseColor; }
    inline const float GetAmbientStrength() const { return m_AmbientStrength; }
    inline const float GetSpecularStrength() const { return m_SpecularStrength; }
    inline const int GetSpecularShine() const { return m_SpecularShine; }
};