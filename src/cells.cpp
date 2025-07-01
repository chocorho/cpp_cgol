#include "cells.hpp"

void Cell::init(float size, float c, float r){
	m_size = size;
	m_rect = {c*m_size, r*m_size, m_size, m_size};
	m_alive = false;

	m_id = std::to_string((int)r) + " " + std::to_string((int)c);
	//SDL_Log(m_id.c_str());

	//SDL_Log("size: %f, x: %f, y: %f, alive: %b\n", m_rect.w, m_rect.x, m_rect.y, m_alive);
}

void Cell::render(SDL_Renderer* renderer){
	if(m_alive){
		SDL_Rect *m_rect_cpy = new SDL_Rect();
		m_rect_cpy->x = m_rect.x;
		m_rect_cpy->y = m_rect.y;
		m_rect_cpy->w = m_size;
		m_rect_cpy->h = m_size;
		SDL_RenderFillRect(renderer, m_rect_cpy);
		delete m_rect_cpy;  // kinda slow, but it fixes the compiler error and avoids memory leaks!
	}
	else{
		SDL_Rect *m_rect_cpy = new SDL_Rect();
		m_rect_cpy->x = m_rect.x;
		m_rect_cpy->y = m_rect.y;
		m_rect_cpy->w = m_size;
		m_rect_cpy->h = m_size;
		SDL_RenderDrawRect(renderer, m_rect_cpy);
		delete m_rect_cpy;
	}
}

float Cell::getSize(){return m_size;}

float Cell::getX(){return m_rect.x;}
float Cell::getY(){return m_rect.y;}

bool Cell::getAlive(){return m_alive;}
void Cell::setAlive(bool val){m_alive = val;}

/*
bool Cell::operator==(const Cell* cell){
	if(this->m_id == cell->m_id){
		return true;
	}
	return false;
}
*/
