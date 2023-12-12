#include <gtest/gtest.h>

#include <binary_phase-shift_keying_modulation.h>
#include <binary_phase-shift_keying_demodulation.h>

TEST(ExampleTest, example)
{
    ASSERT_TRUE(1 == 1);
}

TEST(ModulationAndDemodulation, TestTogether)
{
    std::vector<bool> signal = {true, false, true, false, true, true};
    BPSKModulation modulation(1, 3, 1, 2);

    modulation.modulate(signal);

    auto in_phase = modulation.getInPhase();
    auto quadrature = modulation.getQuadrature();

    BPSKDemodulation demodulation(3, 2);
    auto demodulated = demodulation.demodulate(in_phase, quadrature);

    for (int i = 0; i < signal.size(); ++i)
    {
        // std::cout << signal[i] << "\t" << demodulated[i] << "\n";
        ASSERT_EQ(signal[i], demodulated[i]);
    }
}
