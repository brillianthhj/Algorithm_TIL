#include <iostream>
#include <ostream>

/*
    - is-a relationship
    - 중복되는 기능이 있을 때, 수정하는 관점에서 한군데에서만 수정하면 돼서 객체지향 관점에서 용이
*/

class USBDevice
{
private:
    long m_id;

public:
    USBDevice(const long& id_in)
        :m_id(id_in)
    {}

    long getID() { return m_id; }

    void plugAndPlay() {}
};

class NetworkDevice
{
private:
    long m_id;

public:
    NetworkDevice(const long& id_in) : m_id(id_in) {}

    long getID() { return m_id; }

    void networking() {}
};

// 다중상속
class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
    USBNetworkDevice(const long& usb_id, const long& net_id)
        : USBDevice(usb_id), NetworkDevice(net_id)
    {}

    // USBNetworkDevice(const long& id)
    //     : USBDevice(id), NetworkDevice(id)
    // {}
};

int main()
{
    USBNetworkDevice my_device(3.14, 6.022);

    my_device.networking();
    my_device.plugAndPlay();

    my_device.USBDevice::getID();
    my_device.NetworkDevice::getID();

    return 0;
}