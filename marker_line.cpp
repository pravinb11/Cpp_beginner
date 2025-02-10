#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <geometry_msgs/msg/point.hpp>

class LineMarkerArrayPublisher : public rclcpp::Node {
public:
    LineMarkerArrayPublisher() : Node("line_marker_array_publisher") {
        publisher_ = this->create_publisher<visualization_msgs::msg::MarkerArray>("visualization_marker_array", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&LineMarkerArrayPublisher::publish_marker_array, this));
    }

private:
    void publish_marker_array() {
        visualization_msgs::msg::MarkerArray marker_array;

        for (int i = 0; i < 3; ++i) {  // Create 3 different line markers
            visualization_msgs::msg::Marker marker;
            marker.header.frame_id = "map";  
            marker.header.stamp = this->get_clock()->now();
            marker.ns = "lines";
            marker.id = i;
            marker.type = visualization_msgs::msg::Marker::LINE_STRIP;  // Use LINE_LIST for separate segments
            marker.action = visualization_msgs::msg::Marker::ADD;
            marker.scale.x = 0.05;  // Line width
            marker.color.r = (i == 0) ? 1.0 : 0.0;
            marker.color.g = (i == 1) ? 1.0 : 0.0;
            marker.color.b = (i == 2) ? 1.0 : 0.0;
            marker.color.a = 1.0;

            // Define points for each line
            geometry_msgs::msg::Point p1, p2;
            p1.x = i * 2.0; p1.y = 0.0; p1.z = 0.0;
            p2.x = i * 2.0 + 1.0; p2.y = 1.0; p2.z = 0.0;

            marker.points.push_back(p1);
            marker.points.push_back(p2);

            marker_array.markers.push_back(marker);
        }

        publisher_->publish(marker_array);
    }

    rclcpp::Publisher<visualization_msgs::msg::MarkerArray>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LineMarkerArrayPublisher>());
    rclcpp::shutdown();
    return 0;
}

