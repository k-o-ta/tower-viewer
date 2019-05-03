#include "document.h"

Document::Document(std::string filepath) {
  this->m_filepath = filepath;
  this->m_page_num = 0;
  this->m_document = poppler::document::load_from_file(filepath);
  this->m_renderer = new poppler::page_renderer();
}

void Document::increment_page() { this->m_page_num++; }
void Document::decrement_page() {
  if (this->m_page_num != 0) {
    this->m_page_num--;
  }
}

poppler::image Document::image() {
  return this->m_renderer->render_page(this->m_document->create_page(this->m_page_num));
}