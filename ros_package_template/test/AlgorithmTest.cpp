#include "ros_package_template/Algorithm.hpp"

// gtest
#include <gtest/gtest.h>

// STD
#include <vector>

using namespace ros_package_template;

TEST(Algorithm, getWithoutSet)
{
  Algorithm algorithm;
  const double average = algorithm.getAverage();
  EXPECT_EQ(0.0, average);
}

TEST(Algorithm, singleDataPoint)
{
  const double inputData = 100.0 * (double)rand() / RAND_MAX;
  Algorithm algorithm;
  algorithm.addData(inputData);
  const double average = algorithm.getAverage();
  EXPECT_NEAR(inputData, average, 1e-10);
}

TEST(Algorithm, multipleDataPoints)
{
  size_t nMeasurements = 100;
  std::vector<double> inputData(nMeasurements);
  double sum = 0.0;
  for (auto& data : inputData) {
    data = 100.0 * (double)rand() / RAND_MAX;
    sum += data;
  }

  Algorithm algorithm;
  for (const auto data : inputData) {
    algorithm.addData(data);
  }
  const double average = algorithm.getAverage();
  EXPECT_NEAR(sum / nMeasurements, average, 1e-10);
}
