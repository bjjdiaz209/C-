#pragma once

class m_string
{
private:
    size_t len;
    char* valor;

public:
    m_string(const char* str);
    m_string();
    ~m_string();
    const char* get_str() const;
    m_string(const m_string& str);
    m_string& operator=(const m_string& str);
};