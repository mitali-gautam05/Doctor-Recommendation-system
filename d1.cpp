#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;
string toLower(const string& str) {
 string lowered = str;
 transform(lowered.begin(), lowered.end(), lowered.begin(), ::tolower);
 return lowered;
}
class Patient {
private:
 string Name_of_Patient;
 string Date_of_Birth;
 string Gender;
 string Marital_status;
 string Address;
 string Phone_number;
 string Allergic_details;
 string Blood_group;
public:
 void Patient_details() {
 cout << "==================== Patient Registration ===================="
<< endl;
 cout << "➡️ Enter the name of the Patient: ";
 getline(cin, Name_of_Patient);
 cout << "➡️ Enter your Date of Birth (DD/MM/YYYY): ";
 getline(cin, Date_of_Birth);
 while (true) {
 cout << "➡️ Enter your Gender (Male/Female/Trans): ";
 getline(cin, Gender);
 string gender_lower = toLower(Gender);
 if (gender_lower == "male" || gender_lower == "female" || gender_lower == "trans") {
 break;
 }
 cout << "❌ Invalid gender. Please enter Male, Female or Trans." << endl;
 }
 while (true) {
    cout << "➡️ Enter Marital Status (Married/Unmarried): ";
    getline(cin, Marital_status);
    string status_lower = toLower(Marital_status);
    if (status_lower == "married" || status_lower == "unmarried") {
    break;
    }
    cout << "❌ Invalid marital status. Please enter Married or Unmarried." << endl;
    }
    cout << "➡️ Enter your Address: ";
    getline(cin, Address);
    while (true) {
    cout << "➡️ Enter your Phone Number (10 digits): ";
    getline(cin, Phone_number);
    if (Phone_number.length() == 10 && all_of(Phone_number.begin(),
   Phone_number.end(), ::isdigit)) {
    break;
    }
    cout << "❌ Invalid phone number. Please enter a 10-digit number." << endl;
    }
    cout << "➡️ Enter your Blood Group: ";
    getline(cin, Blood_group);
    string allergyInput;
    cout << "➡️ Do you have any allergies? (Yes/No): ";
    getline(cin, allergyInput);
    if (toLower(allergyInput) == "yes") {
    cout << "➡️ Please specify allergic medicine or food: ";
    getline(cin, Allergic_details);
    } else {
    Allergic_details = "NO";
    }
    cout <<
   "==============================================================\n"
   << endl;
    }
    void displayPatientDetails() {
    cout << "\n==================== Patient Details Summary====================" << endl;
    cout << "|➡️ Name : " << Name_of_Patient << endl;
    cout << "|➡️ DOB : " << Date_of_Birth << endl;
    cout << "|➡️ Gender : " << Gender << endl;
    cout << "|➡️ Marital Status : " << Marital_status << endl;
    cout << "|➡️ Address : " << Address << endl;
    cout << "|➡️ Phone Number : " << Phone_number << endl;
 cout << "|➡️ Blood Group : " << Blood_group << endl;
 cout << "|➡️ Allergies : " << Allergic_details << endl;
 cout <<
"===============================================================\n"
<< endl;
 }
 void writeToFile() {
 ofstream outFile("patient_details.txt", ios::app);
 if (outFile.is_open()) {
 outFile << "================ Patient Details ================\n";
 outFile << "➡️ Name: " << Name_of_Patient << "\n";
 outFile << "➡️ Date of Birth: " << Date_of_Birth << "\n";
 outFile << "➡️ Gender: " << Gender << "\n";
 outFile << "➡️ Marital Status: " << Marital_status << "\n";
 outFile << "➡️ Address: " << Address << "\n";
 outFile << "➡️ Phone Number: " << Phone_number << "\n";
 outFile << "➡️ Blood Group: " << Blood_group << "\n";
 outFile << "➡️ Allergic Details: " << Allergic_details << "\n";
 outFile <<
"=================================================\n\n";
 outFile.close();
 cout << "✅ Patient details have been written to patient_details.txt.\n" << endl;
 } else {
 cout << "❌ Error opening file!" << endl;
 }
 }
};
// Base Doctor class
class Doctor {
    protected:
     string name;
     string specialization;
     int experience;
    public:
     Doctor(string n, string spec, int exp) {
     name = n;
     specialization = spec;
     experience = exp;
     }
     string getName() { return name; }
     string getSpecialization() { return specialization; }
     void displayDoctorDetails() {
     cout << "-------------------------------------------------" << endl;
     cout << "| Doctor : " << name << endl;
     cout << "| Specialization: " << specialization << endl;
     cout << "| Experience : " << experience << " years" << endl;
     cout << "-------------------------------------------------" << endl;
     // Load ratings from file
     ifstream inFile("star_ratings.txt");
     string line;
     bool found = false;
     while (getline(inFile, line)) {
     if (line.find(name) != string::npos) {
     cout << "⭐ Rating: " << line.substr(line.find(":") + 1) << "/5" << endl;
     found = true;
     break;
     }
     }
     if (!found) {
     cout << "⭐ Rating: Not rated yet." << endl;
     }
     inFile.close();
     }
    };
    // Specializations
    class Surgeon : public Doctor { public: Surgeon(string n, int e) : Doctor(n, "Surgeon", e) {} };
    class Cardiologist : public Doctor { public: Cardiologist(string n, int e) : Doctor(n,
        "Cardiologist", e) {} };
        class Neurologist : public Doctor { public: Neurologist(string n, int e) : Doctor(n,
        "Neurologist", e) {} };
        class Orthopedic : public Doctor { public: Orthopedic(string n, int e) : Doctor(n,
        "Orthopedic", e) {} };
        class Gynecologist : public Doctor { public: Gynecologist(string n, int e) : Doctor(n,
        "Gynecologist", e) {} };
        class Dentist : public Doctor { public: Dentist(string n, int e) : Doctor(n, "Dentist", e) {} };
        class Dermatologist : public Doctor { public: Dermatologist(string n, int e) : Doctor(n,
        "Dermatologist", e) {} };
        class Psychiatrist : public Doctor { public: Psychiatrist(string n, int e) : Doctor(n,
        "Psychiatrist", e) {} };
        class Gastroenterologist : public Doctor { public: Gastroenterologist(string n, int e) :
        Doctor(n, "Gastroenterologist", e) {} };
        class Pediatrician : public Doctor { public: Pediatrician(string n, int e) : Doctor(n,
        "Pediatrician", e) {} };
        class Allergist : public Doctor { public: Allergist(string n, int e) : Doctor(n, "Allergist", e) {}
        };
        class Hospital {
        private:
         vector<Doctor*> doctors;
        public:
         void addDoctor(Doctor* doc) {
         doctors.push_back(doc);
         }
         void suggestDoctors(string disease) {
         map<string, string> diseaseMap = {
         {"heart", "Cardiologist"},
         {"brain", "Neurologist"},
         {"surgery", "Surgeon"},
         {"bones", "Orthopedic"},
         {"pregnancy", "Gynecologist"},
         {"teeth", "Dentist"},
         {"skin", "Dermatologist"},
         {"mental", "Psychiatrist"},
         {"stomach", "Gastroenterologist"},
         {"children", "Pediatrician"},
         {"allergy", "Allergist"}
         };
         string lowerDisease = toLower(disease);
         bool found = false;
         if (diseaseMap.find(lowerDisease) != diseaseMap.end()) {
         string spec = diseaseMap[lowerDisease];
         cout << "\n================== Doctor Suggestions ==================\n";
 for (auto& doc : doctors) {
 if (doc->getSpecialization() == spec) {
 doc->displayDoctorDetails();
 rateDoctor(doc->getName());
 found = true;
 }
 }
 }
 if (!found) {
 cout << "❌ No doctors found for this disease.\n";
 }
 cout <<
"========================================================\n" << endl;
 }
 void rateDoctor(const string& doctorName) {
    int rating;
    cout << "➡️ Rate Dr. " << doctorName << " (1-5): ";
    cin >> rating;
    cin.ignore();
    rating = max(1, min(5, rating));
    ofstream file("star_ratings.txt", ios::app);
    if (file.is_open()) {
    file << doctorName << ": " << rating << "\n";
    file.close();
    cout << "✅ Your rating has been recorded.\n";
    }
    }
   };
   // Main Function
   int main() {
    Patient p;
    p.Patient_details();
    p.displayPatientDetails();
    p.writeToFile();
    Hospital h;
    h.addDoctor(new Cardiologist("Dr. John Doe", 10));
    h.addDoctor(new Neurologist("Dr. Jane Smith", 8));
    h.addDoctor(new Surgeon("Dr. Richard Roe", 12));
    h.addDoctor(new Orthopedic("Dr. Raj Patel", 9));
    h.addDoctor(new Gynecologist("Dr. Priya Sharma", 11));
    h.addDoctor(new Dentist("Dr. Amit Verma", 7));
    h.addDoctor(new Dermatologist("Dr. Sneha Kapoor", 6));
    h.addDoctor(new Psychiatrist("Dr. Rahul Mehra", 10));
    h.addDoctor(new Gastroenterologist("Dr. Neha Joshi", 13));
    h.addDoctor(new Pediatrician("Dr. Karan Singh", 8));
    h.addDoctor(new Allergist("Dr. Anjali Rao", 9));
    string disease;
    cout << "Enter your problem (Heart, Brain, Surgery, Bones, Pregnancy, Teeth, Skin,Mental, Stomach, Children, Allergy): ";
    getline(cin, disease);
    h.suggestDoctors(disease);
   return 0;
   }