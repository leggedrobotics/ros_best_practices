#pragma once

#include <cstddef>

namespace ros_package_template {

/*!
 * Class containing the algorithmic part of the package.
 */
class Algorithm
{
 public:
  /*!
   * Constructor.
   */
  Algorithm();

  /*!
   * Destructor.
   */
  virtual ~Algorithm();

  /*!
   * Add new measurement data.
   * @param data the new data.
   */
  void addData(const double data);

  /*!
   * Get the computed average of the data.
   * @return the average of the data.
   */
  double getAverage() const;

 private:

  //! Internal variable to hold the current average.
  double average_;

  //! Number of measurements taken.
  size_t nMeasurements_;
};

} /* namespace */
