#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager

void setup() {
    WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
    

    // put your setup code here, to run once:
    Serial.begin(115200);
    
    // WiFi.mode(WiFi_STA); // it is a good practice to make sure your code sets wifi mode how you want it.

    //WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wm;

//IP Adresleri ayarlanır. Siz kendi networkünüze göre ayarlamalısınız  Start
 IPAddress _ip = IPAddress(192, 168, 1, 150);
  IPAddress _gw = IPAddress(192, 168, 1, 1);
 IPAddress _sn = IPAddress(255, 255, 255, 0);
  //IP Adresleri ayarlanır. End

//Statik IP set edilir.
  wm.setSTAStaticIPConfig(_ip, _gw, _sn);


    bool res;
    // res = wm.autoConnect(); // auto generated AP name from chipid
    // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
    res = wm.autoConnect("ESP8266_Wifi","12345678"); // Eğer daha önce bir bağlantı yapılmamış ise ESP8266 AP modunda başlıyor. Bunun için bilgileri giriyoruz.
  //ESP8266_EH kısmını wifi networkleri içinde görüp 123456 bilgisi ile bağlanıyor olacağız. 
  //Sonrasında kendi ağımızı seçip bilgileri ESP8266 içinde kaydetmiş oluyoruz.

    if(!res) {
        Serial.println("Bağlantı Hatası");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("Bağlandı :)");

        Serial.println("local ip");
        Serial.println(WiFi.localIP());
    }


}

void loop() {

    
}
