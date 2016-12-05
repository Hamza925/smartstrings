#ifndef STRING_H
#define	STRING_H

class String{
private:
    StringBuffer* _str;
public:
    String();
    ~String();
    String(const String&);
    String(char* ,int);
    void append(char);
    int length() const;
    char charAt(int) const;
};


#endif	/* STRING_H */

