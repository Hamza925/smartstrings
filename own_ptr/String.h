#ifndef STRING_H
#define	STRING_H

class String{
private:
    StringBuffer* _str;
    mutable bool owned;
public:
    String();
    ~String();
    String(const String&);
    String(char* ,int);
    void append(char);
    void release();
    int length() const;
    char charAt(int) const;
};


#endif	/* STRING_H */

