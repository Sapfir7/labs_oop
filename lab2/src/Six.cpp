#include "Six.h"

Six::Six() :_size {0} , _array {nullptr}{
    std::cout << "Default constructor" << "\n"; 
}
long long Six::getSize(){
    return _size;
}

unsigned char* Six::getArray(){
    return _array;
}

Six::Six(const size_t &n,unsigned char t){
    std::cout << "Fill constructor" << "\n";
    if (t > '5' || t < '0'){
        throw std::invalid_argument("Unacceptable value");
    }
    _array = new unsigned char[n];
    for (long long i = 0; i < n; ++i){
        _array[i] = t;
    }
    _size = n;
}

Six::Six(const std::initializer_list<unsigned char> &t){
    std::cout << "Initializer list constructor" << "\n";
    _array = new unsigned char[t.size()];
   
    long long i{t.size()-1};
    for (auto c: t){
        
        if (c > '5' || c < '0'){
            throw std::invalid_argument("Unacceptable value");
        }
        _array[i] = c;
        i--;
    }
    _size = t.size();
}

Six::Six(const std::string &t){
    std::cout << "Copy string constructor" << "\n";
    _array = new unsigned char[t.size()];
   
    for (long long i{0}; i < t.size(); ++i){
        if (t[i] > '5' || t[i] < '0'){
            throw std::invalid_argument("Unacceptable value");
        }
        _array[t.size() - 1 - i] = t[i];
    }
    _size = t.size();
}

Six::Six(const Six &other){
    std::cout <<"Copy constructor" << "\n";
    _size = other._size;
    _array = new unsigned char[other._size];
    for (int i{0}; i < other._size; ++i){
        _array[i] = other._array[i];
    }

}

Six::Six(Six &&other) noexcept {
    std::cout << "Move constructor" << "\n";
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Six Six::add(const Six &other){
    int ost = 0;
    Six tmp {other};
    size_t len;
    Six newObj (std::max(_size, other._size) + 1, '0'); 
    
    if (_size > other._size){
        for (size_t i =0; i < other._size; ++i){
            //std::cout << "First: " << (_array[i] - '0') << " Second: " << (other._array[i] - '0') << " ost: " << ost << " res: " << (((_array[i] - '0') + (other._array[i] - '0') + ost) % 6)  << " new ost: " << ((_array[i] - '0') + (other._array[i] - '0') + ost) / 6 << "\n";
            newObj._array[i] = (((_array[i] - '0') + (other._array[i] - '0') + ost) % 6) + '0';
            ost = ((_array[i] - '0') + (other._array[i] - '0') + ost) / 6;
        }

        for (size_t i = other._size; i < _size; ++i){
            //std::cout << "First: " << (_array[i] - '0') << " ost: " << ost << " res: " << (((_array[i] - '0')  + ost) % 6)  << " new ost: " << ((_array[i] - '0') + ost) / 6 << "\n";
            newObj._array[i] = (((_array[i] - '0') +  + ost) % 6) + '0';
            ost = ((_array[i] - '0') + ost) / 6;
        }
        newObj._array[_size] = (ost + '0');
    }
    // other > size
    else{
        for (size_t i =0; i < _size; ++i){
            //std::cout << "First: " << (_array[i] - '0') << " Second: " << (other._array[i] - '0') << " ost: " << ost << " res: " << (((_array[i] - '0') + (other._array[i] - '0') + ost) % 6) + '0' << " new ost: " << ((_array[i] - '0') + (other._array[i] - '0') + ost) / 6 << "\n";
            newObj._array[i] = (((_array[i] - '0') + (other._array[i] - '0') + ost) % 6) + '0';
            ost = ((_array[i] - '0') + (other._array[i] - '0') + ost) / 6;
        }

        for (size_t i = _size; i < other._size; ++i){
            newObj._array[i] = (((other._array[i] - '0') +  + ost) % 6) + '0';
            ost = ((other._array[i] - '0') + ost) / 6;
        }
        newObj._array[other._size] = (ost + '0');
    }
    //std::cout << newObj._size << " " << newObj._array[newObj._size] << "\n";
    for (long long i = newObj._size-1; i > 0; --i){
        if ( newObj._array[i] == '0'){
            newObj._size--;
        }
        else{
            break;
        }
    }
    
    //newObj._size = len;
    return newObj;
}

Six Six::remove(const Six &other){
    if (this->operator<(other)){
        throw std::logic_error("Result of removing cant be < 0");
    }
    int borrow =0;
    for (long long i = 0; i < other._size; ++i){
        //std::cout << "First: " << (int)(_array[i] - '0') << " Second: " << (int)(other._array[i] - '0') << " res: " << (int)(_array[i] - '0') - (int)(other._array[i] - '0') << "\n";
        int diff = (int)(_array[i] - '0') - (int)(other._array[i] - '0') - borrow;
        if (diff < 0){
            borrow = 1;
            diff += 6;
        }
        else{
            borrow = 0;
        }
        std::string res;
        //res= (std::string)diff;
        //std::cout << diff << " " <<  diff + '0'<< "\n";
        _array[i] = diff + '0';
    }
    for (long long i = _size-1;i > 0; --i){
        if (_array[i] == '0'){
            _size--;
        }
        else{
            break;
        }
    }
    return *this;
}

bool Six::equals(const Six &other) const{
    if (_size != other._size){
        return false;
    }
    for (int i{0}; i < _size; ++i){
        if (_array[i] != other._array[i]){
            return false;
        }
    }
    return true;

}

bool Six::greaterThan(const Six &other) const{
    if (_size > other._size){
        return true;
    }
    else if (_size < other._size){
        return false;
    }

    for (long long i{_size - 1}; i >= 0; --i){
        if (_array[i] > other._array[i]){
            return true;
        }
        else if (_array[i] < other._array[i]){
            return false;
        }
    }
    return false;
}

bool Six::lessThan(const Six &other) const{
    if (_size < other._size){
        return true;
    }
    else if (_size > other._size){
        return false;
    }
    for (long long i{_size-1}; i >=0; --i){
        if (_array[i] < other._array[i]){
            return true;
        }
        else if (_array[i] > other._array[i]){
            return false;
        }
    }
    return false;
}

std::ostream &Six::print(std::ostream &os){
    if (_size == 0){
        os << '0';
        return os;
    }
    for (long long i{_size - 1}; i >= 0; --i){
        os << _array[i];
        
    }
    return os;
}

Six Six::operator +(const Six& other) {
    return add(other);
};

Six Six::operator -(const Six& other) {
    return remove(other);
}

bool Six::operator ==(const Six& other) const {
    return equals(other);
}

bool Six::operator >(const Six& other) const {
    return greaterThan(other);
}

bool Six::operator <(const Six& other) const {
    return lessThan(other);
}

Six & Six::operator =(const Six& other){
    if (_array != nullptr){
        delete[] _array;
        _array = nullptr;
    }
    _size = other._size;
    _array = new unsigned char[_size];
    for (long long i = 0; i < _size; ++i){
        _array[i] = other._array[i];
    }
    return * this;
}

Six & Six::operator =(Six&& other){
    if (_array != nullptr){
        delete[] _array;
    }
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array=nullptr;
    return *this;
}

std::ostream &operator <<(std::ostream& os, Six& object) {
    return object.print(os);
}

std::istream &operator >>(std::istream& is, Six& object) {
    std::string buffer;
    is >> buffer;
    object = Six(buffer);
    return is;
}

Six::~Six() noexcept{
    std::cout << "Deleting six obj" << "\n";
    if (_size >0){
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}
