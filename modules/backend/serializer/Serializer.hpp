#pragma once

#include "SerializerHelper.hpp"
#include "file_manager/FileManager.hpp"
#include "file_manager/Paths.hpp"
#include "staff/Staff.hpp"

namespace serde
{

void loadStaffData(clinic::staff::Staff& staff)
{
    FileManager file_manager(path::DEFAULT, "staff.proto", FileManager::FileMode::Input);
    auto& input_file = file_manager.getFileRef();
    proto_staff::Staff proto_staff{};
    proto_staff.ParseFromIstream(&input_file);
    deserializeStaff(staff, proto_staff);

    google::protobuf::ShutdownProtobufLibrary();
}

void saveStaffData(const clinic::staff::Staff& staff)
{
    FileManager file_manager(path::DEFAULT, "staff.proto", FileManager::FileMode::Output);
    auto& output_file = file_manager.getFileRef();
    serializeStaff(staff).SerializeToOstream(&output_file);

    google::protobuf::ShutdownProtobufLibrary();
}

} // namespace serde
