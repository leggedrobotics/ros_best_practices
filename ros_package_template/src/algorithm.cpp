#include "ros_package_template/algorithm.hpp"

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/count.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <utility>

namespace ros_package_template
{

using namespace boost::accumulators;

struct Algorithm::Data
{
  accumulator_set<double, features<tag::mean, tag::count>> acc;
};

Algorithm::Algorithm() {data_ = std::make_unique<Data>();}

Algorithm::~Algorithm() = default;

void Algorithm::addData(const double data) {data_->acc(data);}

void Algorithm::addData(const Eigen::VectorXd & data)
{
  for (auto i = 0; i < data.size(); ++i) {
    addData(data[i]);
  }
}

double Algorithm::getAverage() const {return count(data_->acc) ? mean(data_->acc) : 0;}

}  // namespace ros_package_template
