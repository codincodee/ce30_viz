#ifndef OPERATION_HANDLER_H
#define OPERATION_HANDLER_H

#include <memory>
// #include <pcl/visualization/pcl_visualizer.h>
#include "static_view.h"
#include <chrono>
#include <unordered_map>

namespace pcl {
  namespace visualization {
    class PCLVisualizer;
    class MouseEvent;
    class KeyboardEvent;
    class PointPickingEvent;
  } // namespace visualization
} // namespace pcl

namespace ce30_pcviz {
struct CtrlShortcut {
  std::string key;
  std::function<void()> callback;
  std::string description;
};

class OperationHandler
{
public:
  OperationHandler(std::shared_ptr<pcl::visualization::PCLVisualizer> viz);
  void UseAerialView();
  void UseVerticalView();
  void AddShortcut(const CtrlShortcut& shortcut);
  std::vector<CtrlShortcut> GetAllCtrlShortcuts();
  std::vector<std::pair<std::string, std::string>> CtrlShortcutMap();
  void PrintShortcuts();
  static bool IsNumKey(const std::string& key);
protected:
  void HandleMouseEvent(const pcl::visualization::MouseEvent& event);
  void HandleKeyboardEvent(const pcl::visualization::KeyboardEvent& event);
  void HandlePointPickingEvent(
      const pcl::visualization::PointPickingEvent& event);
private:
  std::shared_ptr<pcl::visualization::PCLVisualizer> viz_;
  std::unique_ptr<StaticView> aerial_view_;
  std::unique_ptr<StaticView> vertical_view_;
  std::vector<CtrlShortcut> ctrl_shortcuts_;
  bool double_tapped_;
  bool point_pick_on_;
};
}

#endif // OPERATION_HANDLER_H
