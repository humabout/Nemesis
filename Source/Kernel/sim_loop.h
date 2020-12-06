// sim_loop.h


#ifndef SIM_LOOP_H
#define SIM_LOOP_H


// Inclusions
#include <vector>
#include "block.h"
#include "End_Conditions/end_condition.h"


//------------------------------------------------------------------------------
// Name:    kernel
// Purpose: This namespace holds all parts of the simulation kernel.
//------------------------------------------------------------------------------
namespace kernel
{


  //----------------------------------------------------------------------------
  // Name:    SimLoop
  // Purpose: This class is responsible for running the simulation loop until
  //          end conditions are met. It will use a strategy pattern to compose
  //          various parts of the loop, like end conditions and integration
  //          method from parts to give the user more flexibility when setting
  //          up a simulation.
  //----------------------------------------------------------------------------
  class SimLoop
  {
  public:
    // Constructors
    SimLoop();
    SimLoop(double      time_step_,
            State::type integration_method_);

    // Destructor
    ~SimLoop();

    // Functionality
    void addBlock(Block* block_);
    void addEndCondition(EndCondition* end_condition_);
    void operator<< (Block* block_);
    void operator<< (EndCondition* condition_);
    void run(void);

  private:
    // Member Variables
    kernel::State*             Integrator;
    std::vector<Block*>        Blocks;
    std::vector<EndCondition*> End_Conditions;
    double                     Time_Step;

    // Functionality
    bool isEnd(void) const;

  }; // !SimLoop


} // !kernel


#endif // !SIM_LOOP_H
