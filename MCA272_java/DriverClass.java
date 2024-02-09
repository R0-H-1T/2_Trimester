abstract public class Patient {
	abstract void patientInfo1();
	abstract void patientInfo2();
}


class PersonalInfo extends Patient {
	void patientInfo1(){
		String p_name = "Hemanth";
        int p_age = 32;
        String p_location = "Bangalore";

        System.out.println("Name: " + p_name);
        System.out.println("Patient Name: " + p_name);

	}
}

class HealthInfo extends Patient {
    void patientInfo2(){
        
    }
}


public class DriverClass {
    public static void main(String[] args){
        
    }
}
