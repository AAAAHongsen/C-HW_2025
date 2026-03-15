/**
* @author       洪萱穎  < s1132044@mail.yzu.edu.tw >
* @version      1.0
* @since        1.0
*/
#include <iostream>
using namespace std;

/**
* BMI
* <p>
    BMI = [ Weight(kg) / Height (m)² ]
  </p>
*
* @param  height (double) cm
* @param  weight (double) kg
* @return BMI
*/
double BMI(double h, double w)
{
    double S;
    h = h / 100;
    return S = w / (h * h);
}

/**
* check figure
*
* <p> 重度肥胖：BMI >= 40 </p>
* <p> 中度肥胖：35 <= BMI < 40 </p>
* <p> 輕度肥胖：30 <= BMI < 35 </p>
* <p> 過重: 25 <= BMI < 30 </p>
* <p> 體重正常: 18.5 <= BMI < 25 </p>
* <p> 稍微過輕: 17 <= BMI < 18.5 </p>
* <p> 中度過輕: 16 <= BMI < 17 </p>
* <p> 嚴重瘦弱: BMI < 16 </p>
*
* @information https://www.ramsayhealth.co.uk/treatments/weight-loss-surgery/bmi/bmi-formula?fbclid=IwY2xjawFyPQlleHRuA2FlbQIxMAABHd36f9gtnLDOjF3sqrWimbRxjlPU-xtN3ShGPMg_s1drdAG1uYyof3GPbw_aem_sHJvXBsS1fosgU5q0_xDqA
* @param  S (double) BMI值
* @return check string
*/
string F(double S)
{
    /**
    * <p> string 身材 </p>
    * <p> S BMI值 </p>
    */
    string figure;
    if (S >= 40) figure = "重度肥胖，建議需立即進行健康體重管理";
    else if (S >= 35) figure = "中度肥胖，建議勤快運動並進行飲食管理";
    else if (S >= 30) figure = "輕度肥胖，建議多加運動、調整飲食";
    else if (S >= 25) figure = "過重，建議多運動";
    else if (S >= 18.5)figure = "體重正常，很棒，繼續保持!";
    else if (S >= 17)figure = "稍微過輕，建議均衡飲食";
    else if (S >= 16)figure = "中度過輕，建議均衡飲食及規律運度";
    else if (S < 16)figure = "嚴重瘦弱，建議需立即進行健康體重管理並均衡飲食及運動";
    return figure;
}
int main()
{
    cout << "BMI=體重/(身高*身高)" << endl;

    /**
    * h 身高(cm)
    */
    double h = 0;
    cout << "請輸入身高(公分)" << endl;
    cin >> h;

    /**
    * w 體重(kg)
    */
    double w = 0;
    cout << "請輸入體重(公斤)" << endl;
    cin >> w;

    /**
    * S BMI值
    */
    double S = 0;
    S = BMI(h, w);
    cout << "您的BMI值為:" << BMI(h, w) << endl;

    string figure;
    figure = F(S);
    cout << "您" << figure << endl;

}