#include <rendering/Renderer.h>

Renderer::Renderer (void) {}

Renderer::~Renderer (void) {}

void Renderer::setClearColor (Color color)
{
    glm::vec4 normalizedColors = color.normalize();
    glClearColor(normalizedColors.r, normalizedColors.g, normalizedColors.b, normalizedColors.a);
}

void Renderer::clear (void)
{   
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::swap (void)
{
    vglSwapBuffers(GL_FALSE);
}

void Renderer::draw (const RenderObject & object)
{
    glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(object.getVertexStride(), GL_FLOAT, 0, object.getLocalVertices());
	glColorPointer(object.getColorStride(), GL_FLOAT, 0, object.getVertexColors());
	glDrawArrays(GL_TRIANGLES, 0, object.getTotalVertices());
	
    glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}