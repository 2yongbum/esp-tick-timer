#pragma once
#include <Arduino.h>

enum Unit {SEC, MIN, HOUR};

class TickTimer
{
  uint32_t _timer;
  Unit _unit;
  uint32_t _tick_ms;
  uint32_t _timer_s;
  uint32_t _remain_s = 0;
  uint32_t _tick_cnt = 0;
  bool _running = false;
public:
  // TickTimer(uint32_t timer, uint32_t tick_ms);
  TickTimer(uint32_t timer, Unit unit, uint32_t tick_ms);
  void set(uint32_t timer_m);
  void start(uint32_t timer_m=0);
  void pause();
  void resume();
  void stop();
  bool tick();
  uint32_t remains() const;
};