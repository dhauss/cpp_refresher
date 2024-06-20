#pragma once

template <typename T>
class Matrix
{
public:
    Matrix();
    Matrix(const T &A, const T &B, const T &C, const T &D);

    /****************/
    /* RULE OF FIVE */
    /****************/
    ~Matrix() noexcept;
    Matrix(const Matrix &other); // copy constr
    Matrix &operator=(const Matrix &other); // copy assignm operator
    Matrix(Matrix &&other) noexcept; // move constr
    Matrix &operator=(Matrix &&other) noexcept; // move assignm operator;

    Matrix operator+(const Matrix &rhs);
    Matrix &operator+=(const Matrix &rhs);
    Matrix operator-(const Matrix &rhs);
    Matrix &operator-=(const Matrix &rhs);

    void print_matrix() const;

    T get_A() const;
    T get_B() const;
    T get_C() const;
    T get_D() const;

    void set_A(const T &new_A);
    void set_B(const T &new_B);
    void set_C(const T &new_C);
    void set_D(const T &new_D);

private:
    T m_A;
    T m_B;
    T m_C;
    T m_D;
};

template <typename T>
Matrix<T>::Matrix() : m_A(0.0), m_B(0.0), m_C(0.0), m_D(0.0)
{
    std::cout << "Calling Cstr\n";
}

template <typename T>
Matrix<T>::Matrix(const T &A, const T &B, const T &C, const T &D)
    : m_A(A), m_B(B), m_C(C), m_D(D)
{
    std::cout << "Calling Cstr\n";
}

template <typename T>
Matrix<T>::~Matrix() noexcept
{
    std::cout << "Calling Dstr\n";
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T> &other)
    : m_A(other.get_A()), m_B(other.get_B()), m_C(other.get_C()),
      m_D(other.get_D())
{
    std::cout << "Copy constructor\n";
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &other)
{
    if (this != &other)
    {
        m_A = other.get_A();
        m_B = other.get_B();
        m_C = other.get_C();
        m_D = other.get_D();
    }

    std::cout << "Copy assignment\n";

    return *this;
}

template <typename T>
Matrix<T>::Matrix(Matrix<T> &&other) noexcept
    : m_A(std::move(other.m_A)), m_B(std::move(other.m_B)),
      m_C(std::move(other.m_C)), m_D(std::move(other.m_D))
{
    other.m_A = T{};
    other.m_B = T{};
    other.m_C = T{};
    other.m_D = T{};

    std::cout << "Move constructor\n";
}

template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&other) noexcept
{
    if (this != &other)
    {
        m_A = std::move(other.m_A);
        m_B = std::move(other.m_B);
        m_C = std::move(other.m_C);
        m_D = std::move(other.m_D);

        other.m_A = T{};
        other.m_B = T{};
        other.m_C = T{};
        other.m_D = T{};
    }

    std::cout << "Move assignment\n";

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs)
{
    auto result = Matrix{};

    result.set_A(this->get_A() + rhs.get_A());
    result.set_B(this->get_B() + rhs.get_B());
    result.set_C(this->get_C() + rhs.get_C());
    result.set_D(this->get_D() + rhs.get_D());

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    this->set_A(this->get_A() + rhs.get_A());
    this->set_B(this->get_B() + rhs.get_B());
    this->set_C(this->get_C() + rhs.get_C());
    this->set_D(this->get_D() + rhs.get_D());

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs)
{
    auto result = Matrix{};

    result.set_A(get_A() - rhs.get_A());
    result.set_B(get_B() - rhs.get_B());
    result.set_C(get_C() - rhs.get_C());
    result.set_D(get_D() - rhs.get_D());

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{
    set_A(get_A() - rhs.get_A());
    set_B(get_B() - rhs.get_B());
    set_C(get_C() - rhs.get_C());
    set_D(get_D() - rhs.get_D());

    return *this;
}

template <typename T>
void Matrix<T>::print_matrix() const
{
    std::cout << m_A << " " << m_B << '\n';
    std::cout << m_C << " " << m_D << "\n\n";
}

template <typename T>
T Matrix<T>::get_A() const
{
    return m_A;
}

template <typename T>
T Matrix<T>::get_B() const
{
    return m_B;
}

template <typename T>
T Matrix<T>::get_C() const
{
    return m_C;
}

template <typename T>
T Matrix<T>::get_D() const
{
    return m_D;
}

template <typename T>
void Matrix<T>::set_A(const T &new_A)
{
    m_A = new_A;
}

template <typename T>
void Matrix<T>::set_B(const T &new_B)
{
    m_B = new_B;
}

template <typename T>
void Matrix<T>::set_C(const T &new_C)
{
    m_C = new_C;
}

template <typename T>
void Matrix<T>::set_D(const T &new_D)
{
    m_D = new_D;
}
