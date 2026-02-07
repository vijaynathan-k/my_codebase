#include <iostream>
#include <thread>

class sample_race_condition
{
public:
    sample_race_condition() = default;
    ~sample_race_condition() = default;

    void increment()
    {
        // Note: No thread protection while updating m_number
        m_number = m_number + 1;
    }

    void decrement()
    {
        // Note: No thread protection while updating m_number
        m_number = m_number - 1;
    }

    int get_number() const
    {
        return m_number;
    }

private:
    int m_number = 0;
};

int main()
{
    std::cout << " Hello from sample race condition!" << std::endl;
    sample_race_condition *rc = new sample_race_condition();
    std::thread t1([rc](){for(int i=0;i<10000;i++){rc->increment();}});
    std::thread t2([rc](){for(int i=0;i<10000;i++){rc->decrement();}});
    t1.join();
    t2.join();
    std::cout << "m_number = " << rc->get_number() << std::endl;
    delete rc;
    return 0;
}