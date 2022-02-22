template<typename T>
struct Ponto{
    T x, y;
    Ponto(T vx = 0, T vy = 0): x(vx), y(vy) {};

    bool operator==(const Ponto<T> &p) const {
    return equals(x, p.x) and equals(y, p.y);
    }

    bool operator!=(const Ponto<T> &p) const {
    return not (*this == p);
    }

    Ponto<T> operator+ (const Ponto<T> &p) const {
        return {p.x + x, p.y + y};
    }

    Ponto<T> operator- (const Ponto<T> &p) const {
        return {p.x - x, p.y - y};
    }
};
