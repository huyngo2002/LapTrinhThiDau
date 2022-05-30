// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q26
class Hybrid: public Motor, public Engine {
  public:
    Hybrid(double ME, double MR, double MI, double EE, double EP) : Motor(ME, MR, MI), Engine(EE, EP){ 
    }
    double runnableTime() const {
      return (Motor::runnableTime() < Engine::runnableTime()) ? Motor::runnableTime() : Engine::runnableTime();
    }
};
