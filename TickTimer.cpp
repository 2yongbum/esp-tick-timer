#include "TickTimer.h"

// TickTimer::TickTimer(uint32_t timer_m, uint32_t tick_ms) :
TickTimer::TickTimer(uint32_t timer, Unit unit, uint32_t tick_ms) :
  _timer(timer), _unit(unit), _tick_ms(tick_ms) 
{
  set(timer);
}

void TickTimer::set(uint32_t timer) 
{
  switch (_unit) {
    case Unit::MIN:
      _timer_s = timer*60;
      break;
    case Unit::HOUR:
      _timer_s = timer*60*60;
      break;
    default:
      _timer_s = timer;
      break;
  }
}

void TickTimer::start(uint32_t timer) 
{
  if (timer) {
    set(timer);
  }
  _remain_s = _timer_s;
  _running = true;
}

void TickTimer::pause() 
{
  _running = false;
}

void TickTimer::resume() 
{
  _running = true;
}

void TickTimer::stop() 
{
  _running = false;
  _remain_s = 0;
}

bool TickTimer::tick() 
{
  if (!_running) {
    return false;
  }

  if (++_tick_cnt * _tick_ms >= 1000) {
    _tick_cnt = 0;
    if (_remain_s > 0) {
      _remain_s--;
    }
  }
  if (_remain_s == 0) {
    _running = false;
    return true;
  }
  return false;;
}

uint32_t TickTimer::remains() const {
  return _remain_s;
}