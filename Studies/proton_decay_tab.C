R__LOAD_LIBRARY($HYP_TOP/lib/libHyperon.so)
R__LOAD_LIBRARY($HYP_TOP/lib/libParticleDict.so)

#include "SelectionManager.h"
#include "EventAssembler.h"
#include "Cut.h"
#include "SelectionParameters.h"

#include "Parameters.h"
#include "SampleSets_Example.h"

#include <cmath>
#include <TFeldmanCousins.h>

void proton_decay_tab() {
    // Constants for lifetime calculations
    const double AvogadroNumberProtons = 2.7e32;

    // Confidence level
    double cl = 0.90; // 90% confidence level

    // Fixed exposure value in kilotons*year
    const double fixedExposure = 100; // Adjust this value as needed

    // Arrays of background and efficiency values to iterate over
    double backgrounds[] = {0.1, 0.01, 0.001};
    double efficiencies[] = {0.1, 0.2, 0.4};

    // Initialize Feldman-Cousins calculator
    TFeldmanCousins fc(cl);

    // Output header
    std::cout << "Efficiency\tBackground\tLifetime Limit (years)" << std::endl;

    for (double eps : efficiencies) {
        for (double bkg : backgrounds) {
            // Calculate the upper limit S for the observed number of events
            double S = fc.CalculateUpperLimit(bkg * fixedExposure, bkg * fixedExposure);

            // Calculate the lifetime limit
            double lifetimeLimit = fixedExposure * eps * AvogadroNumberProtons / S;

            // Output the results
            std::cout << std::fixed << std::setprecision(3) << eps << "\t\t" 
                      << bkg << "\t\t" << std::scientific << lifetimeLimit << std::endl;
        }
    }
}
