#pragma once

#include "SerializerHelper.hpp"
#include "clinic/staff/Staff.hpp"
#include "common/file_manager/FileManager.hpp"
#include "common/file_manager/Paths.hpp"

namespace serde
{

void loadStaffData()
{
    FileManager file_manager(path::DEFAULT, "staff.proto", FileManager::FileMode::Input);
    auto& input_file = file_manager.getFileRef();
    proto_staff::Staff proto_staff{};
    proto_staff.ParseFromIstream(&input_file);
    clinic::staff::Staff staff{};
    deserializeStaff(staff, proto_staff);

    google::protobuf::ShutdownProtobufLibrary();
}

} // namespace serde
