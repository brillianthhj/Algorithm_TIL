#include <iostream>
#include <vector>
#include <string>

/*
    - 제휴: Association (Uses-a)
    - 관계의 형태: 서로가 서로를 호출해서 연관되는 관계, 필요할때만 사용, 용도 외엔 서로 무관
    - 다른 클래스에도 속할 수 있는가? YES (Doctor 안에 Doctor, Patient 안에 Patient, Doctor 안에 Patient, Patient 안에 Doctor)
    - 멤버의 존재를 클래스가 관리? NO, delete를 서로 지워줄 수 있는 관계는 아님
    - 방향성: 단방향 or 양방향
*/

class Doctor;   // forward declaration : 서로 동등한 관계면 전방선언을 하게 됨, Association 관계인 것을 암시하기도 함

class Patient
{
private:
    std::string m_name;
    std::vector<Doctor*> m_doctors;

public:
    Patient(std::string name_in)
        : m_name(name_in)
    {}

    // 앞에 const 붙이면, 벡터에서 아예 new_doctor로 전달되는 포인터 m_doctor[n] 이 영원히 변경 안되니까 아예 막았나봄
    void addDoctor(Doctor* const new_doctor)
    {
        m_doctors.push_back(new_doctor);
    }

    void meetDoctors();

    friend class Doctor;
};

class Doctor
{
private:
    std::string m_name;
    std::vector<Patient*> m_patients;

public:
    Doctor(std::string name_in)
        : m_name(name_in)
    {}

    void addPatient(Patient* const new_patient)
    {
        m_patients.push_back(new_patient);
    }

    friend class Patient;

    void meetPatient()
    {
        for (const auto& patient : m_patients)
            std::cout << m_name << " meets patient : " << patient->m_name << std::endl;
    }

};

void Patient::meetDoctors()
{
    for (const auto& doctor : m_doctors)
        std::cout << "Patient " << m_name << " meets doctor : " << doctor->m_name << std::endl;
}

int main()
{
    Patient* p1 = new Patient("Jack Jack");
    Patient* p2 = new Patient("Dash");
    Patient* p3 = new Patient("Violet");

    Doctor* d1 = new Doctor("Doctor K");
    Doctor* d2 = new Doctor("Doctor L");

    p1->addDoctor(d1);
    d1->addPatient(p1);

    p2->addDoctor(d2);
    d2->addPatient(p2);

    p2->addDoctor(d1);
    d1->addPatient(p2);

    // patients meet doctors
    p1->meetDoctors();
    p2->meetDoctors();

    // doctors meet patients
    d1->meetPatient();
    d2->meetPatient();

    // deletes
    delete p1;
    delete p2;
    delete p3;

    delete d1;
    delete d2;

    return 0;
}