class String {
public:
String() { cout << "default" << endl; }
String(char * n) { cout << "convert" << endl; }
String(const String&) { cout << "copy" << endl; }
~String() { cout << "destructor" << endl; }
private:
char * buf;
};
int main() {
String a("cat"), b = a;
String * ptr = new String("dog");
return 0;}
