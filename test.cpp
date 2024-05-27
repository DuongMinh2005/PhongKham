#include <iostream>
using namespace std;

int main()
{
    bool post,              // posterior: ?
         ante;              // anterior: ?
    int fillings;           // fillings: Y/N
    int tooth_number;       // tooth_number: 1-32
    int surface_num;        // surface_num should be 1-5
    int amal_or_comp;       // amalgum or composite filling
    int cav_deep;           // input for if cavity is deep

    cout << "Is the cavity deep?: 1.Yes 2.No" << endl;
    cin  >> cav_deep;
    if (cav_deep==1)
        cout << "Temporary filling needed. Patient needs to come back for permanent      fill at later date." << endl;
        else if (cav_deep==2)
    {
        cout << "Fillings Needed?: 1.Yes 2.No" << endl;
        cin  >> fillings;
        if (fillings==2)
        {
            cout << "Proceed to 'crowns'" << endl;
        }
        if (fillings==1)
        {
            cout << "Tooth #: " << endl;
            cin >> tooth_number;
            cout << "Tooth # entered is: " << tooth_number << endl;
            // if tooth is posterior
            if (tooth_number>=1&&tooth_number<=5)
            {
                cout << "Posterior Tooth" << endl;
                cout << "1. Amalgam or 2. Composite?" << endl;
                cin  >> amal_or_comp;
                if(amal_or_comp==1)
                    cout << "Amalgam selected." << endl;
                if(amal_or_comp==2)
                    cout << "Composite selected." << endl;
                cout << "Surface #: ";
                cin  >> surface_num;
                cout << "Surface # entered: " << surface_num;
            }
            if (tooth_number>=12&&tooth_number<=16)
            {
                cout << "Posterior Tooth" << endl;
                cout << "1. Amalgam or 2. Composite?" << endl;
                cin  >> amal_or_comp;
                if(amal_or_comp==1)
                    cout << "Amalgam selected." << endl;
                if(amal_or_comp==2)
                    cout << "Composite selected." << endl;
                cout << "Surface #: ";
                cin  >> surface_num;
                cout << "Surface # entered: " << surface_num;
            }
            if (tooth_number>=17&&tooth_number<=21)
            {
                cout << "Posterior Tooth" << endl;
                cout << "1. Amalgam or 2. Composite?" << endl;
                cin  >> amal_or_comp;
                if(amal_or_comp==1)
                    cout << "Amalgam selected." << endl;
                if(amal_or_comp==2)
                    cout << "Composite selected." << endl;
                cout << "Surface #: ";
                cin  >> surface_num;
                cout << "Surface # entered: " << surface_num;
            }
            if (tooth_number>=28&&tooth_number<=32)
            {
                cout << "Posterior Tooth" << endl;
                cout << "1. Amalgam or 2. Composite?" << endl;
                cin  >> amal_or_comp;
                if(amal_or_comp==1)
                    cout << "Amalgam selected." << endl;
                if(amal_or_comp==2)
                    cout << "Composite selected." << endl;
                cout << "Surface #: ";
                cin  >> surface_num;
                cout << "Surface # entered: " << surface_num;
            }
            // if tooth is anterior
            if (tooth_number>=6&&tooth_number<=11)
            {
                cout << "Anterior Tooth" << endl;
                cout << "Composite" << endl;
                cout << "Surface #: ";
                cin  >> surface_num;
                cout << "Surface # entered: " << surface_num;
            }
            if (tooth_number>=22&&tooth_number<=27)
            {
                cout << "Anterior Tooth" << endl;
                cout << "Composite" << endl;
                cout << "Surface #: ";
                cin  >> surface_num;
                cout << "Surface # entered: " << surface_num;
            }
        }
    }
}