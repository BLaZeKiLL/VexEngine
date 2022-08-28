#include "Vex/Vendor.h"

#include "Core/Data.h"

TransformData::TransformData(const glm::vec3 &position, const glm::vec3 &axis, float rotation)
        : m_Position(position), m_Axis(axis), m_Rotation(rotation)
{

}

glm::mat4 TransformData::GetTransform() const
{
    return glm::rotate(
            glm::translate(glm::mat4(1.0), m_Position),
            glm::radians(m_Rotation),
            glm::normalize(m_Axis)
    );
}

void TransformData::RenderUI()
{
    if (ImGui::CollapsingHeader("Transform")) {
        ImGui::InputFloat3("Position", glm::value_ptr(m_Position));
        ImGui::SliderFloat3("Axis", glm::value_ptr(m_Axis), 0.0f, 1.0f);
        ImGui::SliderFloat("Rotation", &m_Rotation, 0.0f, 360.0f);
    }
}

LightData::LightData(const glm::vec3 &position, const glm::vec3 &color) : m_Position(position), m_Color(color)
{}

void LightData::RenderUI()
{
    if (ImGui::CollapsingHeader("Light"))
    {
        ImGui::InputFloat3("Position", glm::value_ptr(m_Position));
        ImGui::ColorPicker3("Color", glm::value_ptr(m_Color));
    }
}

MaterialData::MaterialData(
        const glm::vec4& baseColor,
        float ambientStrength,
        float specularStrength,
        int specularShine
) : m_BaseColor(baseColor), m_AmbientStrength(ambientStrength), m_SpecularStrength(specularStrength), m_SpecularShine(specularShine)
{}

void MaterialData::RenderUI()
{
    if (ImGui::CollapsingHeader("Material"))
    {
        ImGui::ColorPicker4("Base Color", glm::value_ptr(m_BaseColor));
        ImGui::InputFloat("Ambient Strength", &m_AmbientStrength);
        ImGui::InputFloat("Specular Strength", &m_SpecularStrength);
        ImGui::InputInt("Specular Shine", &m_SpecularShine);
    }
}


